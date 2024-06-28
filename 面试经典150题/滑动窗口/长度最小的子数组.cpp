#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
/*
    int getBound(int left, int right, int target, vector<int> &sums){
        int mid;
        while(left < right){
            mid = (left + right) / 2;
            if(sums[mid] >= target)
                right = mid;
            else
                left = mid + 1;
        }
        if(sums[left] >= target)
            return left;
        else
            return -1;
    }

    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int res = 0x3f3f3f;
        vector<int> sum;
        sum.emplace_back(0);
        for(int i = 0; i < n; i++){
            sum.emplace_back(sum[i] + nums[i]);
        }
        for(int i = 1; i < n + 1; i++){
            int left = i;
            int right = n;
            int pos = getBound(left, right, target + sum[i - 1], sum);
            if(pos != -1){
                res = min(res, pos - i + 1);
            }

        }
        return res == 0x3f3f3f ? 0 : res;  
    }
    */

/*
    int minSubArrayLen(int target, vector<int>& nums){
        int n = nums.size();
        int left = 0;
        int right = 0;
        int res = 0x3f3f3f;
        int sum = nums[0];
        while(right < n){
            if(sum < target){
                right++;
                if(right < n){
                    sum += nums[right];
                }
            }
            else{
                res = min(res, right - left + 1);
                if(left < n){
                    sum -= nums[left];
                    left++;
                }
            }
                
        }
        return res == 0x3f3f3f ? 0 : res;
    }*/

    int minSubArrayLen(int target, vector<int>& nums){
        int n = nums.size();
        int left = 0;
        int right = 0;
        int res = 0x3f3f3f;
        int sum = 0;
        while(right < n){
            sum += nums[right++];
            while(sum >= target){
                res = min(res, right - left);
                sum -= nums[left];
                left++;
            }
        }
        return res == 0x3f3f3f ? 0 : res;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,1,1,1,1,1,1,1};
    cout<<sol.minSubArrayLen(9, nums);
    return 0;
}