class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int res = 0;
        for(int i = 0; i < commands.size(); i++)
        {
            if(commands[i] == "DOWN")
                res += n;
            else if(commands[i] == "UP")
                res -= n;
            else if(commands[i] == "RIGHT")
                res++;
            else
                res--;
        }
        return res;
    }
};