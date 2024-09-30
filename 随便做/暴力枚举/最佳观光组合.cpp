class Solution
{
public:
    int maxScoreSightseeingPair(vector<int> &values)
    {
        int n = values.size();
        int plusMax = values[0];
        int res = 0;
        for(int i = 1; i < n; i++)
        {
            res = max(res, plusMax + values[i] - i);
            plusMax = max(plusMax, values[i] + i);
        }
        return res;
    }
};