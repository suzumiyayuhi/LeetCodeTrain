#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int target = 0;
        vector<vector<int>> res;
        for(int i = 0; i < nums.size() - 2; i++){
            if(i != 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right){
                int tem = nums[i] + nums[left] + nums[right];
                if(tem > target){
                    right--;
                }
                else if(tem < target){
                    left++;
                }
                else{
                    res.emplace_back(vector<int>{nums[i], nums[left], nums[right]});
                    left++;
                    while(right != nums.size() - 1 && left < right && nums[right] == nums[right + 1])
                        right--;
                    while(left < right && nums[left] == nums[left - 1])
                        left++;
                }
            }
            
        }
        return res;
    } 
};

int main(){
    Solution sol;
    vector<int> nums = {-1,0,1,2,-1,-4};
    auto aaa = sol.threeSum(nums);
    for(int i = 0; i < aaa.size(); i++){
        cout << aaa[i][0] << " " << aaa[i][1] << " " << aaa[i][2] << endl;
    }
    return 0;
}