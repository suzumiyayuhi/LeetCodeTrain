#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
/*
    vector<int> findIntersectionValues(vector<int> &nums1, vector<int> &nums2)
    {
        int dic1[101] = {0};
        int dic2[101] = {0};
        for (int i = 0; i < nums1.size(); i++)
        {
            dic1[nums1[i]]++;
        }
        vector<int> res;

        int count1 = 0;
        for (int i = 0; i < nums2.size(); i++)
        {
            dic2[nums2[i]]++;
            if (dic1[nums2[i]] != 0)
                count1++;
        }

        int count2 = 0;
        for (int i = 0; i < nums1.size(); i++)
        {
            if (dic2[nums1[i]] != 0)
                count2++;
        }
        res.emplace_back(count2);
        res.emplace_back(count1);

        return res;
    }
*/
    vector<int> findIntersectionValues(vector<int> &nums1, vector<int> &nums2)
    {
        int dic[101] = {0};
        for (int i = 0; i < nums1.size(); i++)
        {
            dic[nums1[i]]++;
        }
        vector<int> res;
        int count1 = 0, count2 = 0;
        for (int i = 0; i < nums2.size(); i++)
        {
            if (dic[nums2[i]] != 0)
            {
                count1++;
                if (dic[nums2[i]] != -1)
                {
                    count2 += dic[nums2[i]];
                    dic[nums2[i]] = -1;
                }
            }
        }
        res.emplace_back(count2);
        res.emplace_back(count1);
        return res;
    }
};