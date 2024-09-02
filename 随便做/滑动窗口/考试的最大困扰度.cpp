#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution
{
public:
    int maxConsecutiveAnswers(string answerKey, int k)
    {
        int tRes = 0, fRes = 0;
        int tTem = k, fTem = k;
        int tleft = 0, tright = 0;
        int fleft = 0, fright = 0;
        for (int i = 0; i < answerKey.size(); i++)
        {
            if (answerKey[tright] == 'F')
            {
                if (tTem)
                {
                    --tTem;
                }
                else
                {
                    while (answerKey[tleft] != 'F')
                        tleft++;
                    tleft++;
                }
            }
            tright++;
            tRes = max(tRes, tright - tleft);

            if (answerKey[fright] == 'T')
            {
                if (fTem)
                {
                    --fTem;
                    
                }
                else
                {
                    while (answerKey[fleft] != 'T')
                        fleft++;
                    fleft++;
                }
                
            }
            fright++;
            fRes = max(fRes, fright - fleft);
        }

        return max(tRes, fRes);
    }
};


int main()
{
    string s = "FFFTTFTTFT";
    int k = 3;
    Solution sol;
    sol.maxConsecutiveAnswers(s, k);
    return 0;
}