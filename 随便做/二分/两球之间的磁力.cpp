class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int left = 1;
        int right = position.back() - position[0];

        int res = left - right;
        while(left <= right)
        {
            int mid = (left + right) / 2;
            int count = 1, pre = 0;
            for(int i = 1; i < position.size(); i++)
            {
                if(position[i] - position[pre] >= mid)
                {
                    pre = i;
                    count++;
                }
            }
            if(count >= m)
            {
                res = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return res;
    }
};