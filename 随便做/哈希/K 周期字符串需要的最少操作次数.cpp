#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:

    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string, int> um;
        int maxCount = 0;
        for(int i = 0; i < word.size(); i += k)
        {
            string temStr = word.substr(i, k);
            um[temStr]++;
            maxCount = max(maxCount, um[temStr]);
        }
        return word.size() / k - maxCount;
    }

};

int main()
{
    string s = "leetcodeleet";
    int k = 4;
    Solution sol;
    sol.minimumOperationsToMakeKPeriodic(s, k);
    return 0;
}