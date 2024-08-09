class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        int min1 = INT_MAX, min2 = INT_MAX;
        for(int i = 0; i < nums1.size(); i++)
        {
            min1 = min(nums1[i], min1);
            min2 = min(nums2[i], min2);
        }

        return min2 - min1;
    }
};