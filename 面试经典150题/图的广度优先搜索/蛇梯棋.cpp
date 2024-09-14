class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size() * board[0].size();
        vector<int> tb(n + 1, 0);
        for(int i = board.size() - 1, l = 0; i >= 0; i--)
        {
            if(i & 1)
            {
                int k = 0;
                for(int j = board[0].size() - 1; j >= 0; j--)
                {
                    tb[board.size() * i + k + 1] = board[l][j];
                    k++;
                }
                
            }
            else
            {
                for(int j = 0; j < board[0].size(); j++)
                    tb[board.size() * i + j + 1] = board[l][j];
            }
            l++;
        }

        vector<int> passed(n + 1, 0);
        passed[0] = 1;
        passed[1] = 1;
        queue<pair<int, int>> qq;
        qq.push(make_pair(1, 0));
        
        while(!qq.empty())
        {
            int curPos = qq.front().first;
            int curStep = qq.front().second;
            qq.pop();
            if(curPos >= n)
                return curStep;
            for(int i = 1; i <= 6; i++)
            {
                if(curPos + i > n)
                    continue;
                if(passed[curPos + i])
                    continue;
                passed[curPos + i] = 1;
                if(tb[curPos + i] != -1)
                    qq.push(make_pair(tb[curPos + i], curStep + 1));
                else
                    qq.push(make_pair(curPos + i, curStep + 1));
            }
        }
        return -1;
    }
};