class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int left = 0, right = 1;
        int res = 0;
        for(int left = 0; left < nums1.size() - 1; left++)
        {
            for(int right = 1; right < nums1.size(); right++)
            {
                if(sub(left, right, nums1, nums2, res))
                    return res;
                continue;
            }
        }
        return res;
    }

    bool sub(int left, int right, vector<int>& nums1, vector<int>& nums2, int &res)
    {
        bool first = true;
        for(int i = 0, j = 0; i < nums2.size(); i++)
        {
            int offset = 0;
            if(j + offset >= left)
            {
                offset = 1;
                if(j + offset >= right)
                    offset = 2;
            }

            if(first)
            {
                res = nums2[i] - nums1[j + offset];
                first = false;
            }
            else
            {
                int tem = nums2[i] - nums1[j + offset];
                if(tem != res)
                    return false;
            }
            j++;
        }
        return true;
    }
};