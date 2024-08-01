#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

using namespace std;

class Solution
{
public:
    /*
        int maxmiumScore(vector<int> &cards, int cnt)
        {
            sort(cards.begin(), cards.end());
            int sum = 0;
            bool flag = true;
            int minOdd = 0;
            int minEven = 0;
            int i = cards.size() - 1;
            if (cnt == 1)
            {
                for (; i >= 0; i--)
                {
                    if (cards[i] % 2 == 0)
                        return cards[i];
                }
                return 0;
            }

            for (; i >= 0; i--)
            {
                if (cnt == 0)
                    break;

                sum += cards[i];
                cnt--;
                if (cards[i] % 2 == 0)
                {
                    minEven = cards[i];
                }
                else
                {
                    minOdd = cards[i];
                    flag = !flag;
                }
            }
            if(flag)
                return sum;
            int res1 = 0, res2 = 0;
            if (!flag)
            {
                if (i < 0)
                    return 0;
                else
                {
                    int temMaxEven1 = 0;
                    int temMaxEven2 = 0;
                    int temMaxOdd = 0;
                    for (; i >= 0; i--)
                    {
                        if ((temMaxEven1 && temMaxEven2) && temMaxOdd)
                            break;
                        if (cards[i] % 2 == 0)
                        {
                            if (temMaxEven1 == 0)
                                temMaxEven1 = cards[i];
                            else
                                temMaxEven2 = cards[i];
                        }
                        else if (temMaxOdd == 0)
                            temMaxOdd = cards[i];
                    }
                    if (temMaxOdd && minEven)
                        res1 = sum - minEven + temMaxOdd;
                    if (temMaxEven1 && temMaxEven2)
                        res2 = sum - minOdd + temMaxEven1;
                }
            }
            return max(res1, res2);
        }
        */
    int maxmiumScore(vector<int> &cards, int cnt)
    {
        sort(cards.begin(), cards.end());
        int sum = 0;
        bool flag = true;
        int minOdd = 0;
        int minEven = 0;
        int i = cards.size() - 1;

        for (; i >= 0; i--)
        {
            if (cnt == 0)
                break;

            sum += cards[i];
            cnt--;
            if (cards[i] % 2 == 0)
            {
                minEven = cards[i];
            }
            else
            {
                minOdd = cards[i];
                flag = !flag;
            }
        }
        if (flag)
            return sum;

        int res1 = 0, res2 = 0;
        int temMaxEven1 = 0;
        int temMaxOdd = 0;
        for (; i >= 0; i--)
        {
            if (temMaxEven1 && temMaxOdd)
                break;
            if (cards[i] % 2 == 0)
            {
                if (temMaxEven1 == 0)
                    temMaxEven1 = cards[i];
            }
            else if (temMaxOdd == 0)
                temMaxOdd = cards[i];
        }
        if (temMaxOdd && minEven)
            res1 = sum - minEven + temMaxOdd;
        if (temMaxEven1)
            res2 = sum - minOdd + temMaxEven1;
        return max(res1, res2);
    }
};

int main()
{
    Solution sol;
    // vector<int> cards = {1, 2, 8, 9};
    //  vector<int> cards = {2, 2, 2, 2};
    vector<int> cards = {2, 3, 5, 5, 10};
    // vector<int> cards = {9,5,9,1,6,10,3,4,5,1};
    // vector<int> cards = {4, 2, 7, 2, 9, 7, 5, 6};
    // vector<int> cards = {4, 8, 3};
    sol.maxmiumScore(cards, 5);

    return 0;
}