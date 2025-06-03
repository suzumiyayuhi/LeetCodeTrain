class Solution
{
public:
    int maxCandies(vector<int> &status, vector<int> &candies, vector<vector<int>> &keys,
                   vector<vector<int>> &containedBoxes, vector<int> &initialBoxes)
    {
        int n = status.size();
        queue<int> curBoxes;
        vector<int> curKeys(n, 0);
        for (int i = 0; i < initialBoxes.size(); i++)
        {
            curBoxes.push(initialBoxes[i]);
        }

        int res = 0;
        bool flag = false;
        do
        {
            flag = false;
            queue<int> temCurBoxes;
            while (!curBoxes.empty())
            {
                int curBox = curBoxes.front();
                curBoxes.pop();
                if (status[curBox] == 1 || curKeys[curBox] == 1)
                {
                    flag = true;
                    res += candies[curBox];
                    for (int i = 0; i < containedBoxes[curBox].size(); i++)
                    {
                        curBoxes.push(containedBoxes[curBox][i]);
                    }

                    for (int i = 0; i < keys[curBox].size(); i++)
                    {
                        curKeys[keys[curBox][i]] = 1;
                    }
                }
                else
                    temCurBoxes.push(curBox);
            }
            curBoxes = temCurBoxes;
        } while (flag);

        return res;
    }
};