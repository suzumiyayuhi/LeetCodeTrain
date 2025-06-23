class Solution {
public:
    int maxDistance(string s, int k) {
        int n = s.size();
        int temRes = 0, temK = k, res = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'N' || s[i] == 'E')
                temRes++;
            else
            {
                if(temK)
                {
                    temK--;
                    temRes++;
                }
                else
                    temRes--;
            }
            res = max(res, temRes);
        }
        temK = k;
        temRes = 0;

        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'S' || s[i] == 'E')
                temRes++;
            else
            {
                if(temK)
                {
                    temK--;
                    temRes++;
                }
                else
                    temRes--;
            }
            res = max(res, temRes);
        }
        temK = k;
        temRes = 0;

        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'N' || s[i] == 'W')
                temRes++;
            else
            {
                if(temK)
                {
                    temK--;
                    temRes++;
                }
                else
                    temRes--;
            }
            res = max(res, temRes);
        }
        temK = k;
        temRes = 0;

        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'S' || s[i] == 'W')
                temRes++;
            else
            {
                if(temK)
                {
                    temK--;
                    temRes++;
                }
                else
                    temRes--;
            }
            res = max(res, temRes);
        }

        return res;
    }
};