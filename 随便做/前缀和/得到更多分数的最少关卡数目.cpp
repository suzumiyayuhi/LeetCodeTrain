#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minimumLevels(vector<int> &possible)
    {
        vector<int> preSum;
        int totalSum = possible[0] == 1 ? 1 : -1;
        preSum.emplace_back(0);
        int alicePlay = 1;
        for (int i = 1; i < possible.size(); i++)
        {
            preSum.emplace_back(totalSum);
            totalSum += possible[i] == 1 ? 1 : -1;
        }
        while (alicePlay < preSum.size())
        {
            if (preSum[alicePlay] > totalSum - preSum[alicePlay])
                return alicePlay;
            alicePlay++;
        }

        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> gg{1, 0, 1, 0};
    cout << sol.minimumLevels(gg);
    return 0;
}