#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
/*
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int temLen = nums[0];
        for(int i = 1; i < n - 1; i++){
            if(temLen < i)
                break;
            if(temLen < i + nums[i]){
                temLen = i + nums[i];
            }
        }
        return temLen >= n - 1;
    }*/

        bool canJump(vector<int>& nums) {
        int n = nums.size();
        int temLen = nums[0];
        for(int i = 0; i < n; i++){
            if(temLen < i)
                return false;
            if(temLen < i + nums[i]){
                temLen = i + nums[i];
            }
        }
        return true;
    }
};

int main(){
    vector<int> sss = {1,1,0,1};
    Solution sol;
    cout<< sol.canJump(sss);
    return 0;
}