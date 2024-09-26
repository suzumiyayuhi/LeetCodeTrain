class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int a = 0;
        int b = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            int tem = nums[i];
            a += tem;
            while(tem)
            {
                b += tem % 10;
                tem /= 10;
            }
        }
        return a - b;
    }
};