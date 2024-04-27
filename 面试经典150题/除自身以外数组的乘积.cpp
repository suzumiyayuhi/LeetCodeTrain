#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void test(vector<int> sss){
    for(int i = 0; i < sss.size(); i++){
        cout<<sss[i]<<" ";
    }
    cout<<endl;
}

class Solution {
public:
/*
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        for(int i = 1; i < n; i++){
            res[i] = res[i - 1] * nums[i - 1];
        }
        int temRight = 1;
        for(int i = n - 2; i >= 0; i--){
            temRight *= nums[i + 1];
            res[i] *= temRight;
        }
        return res;
    }
*/
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        res.emplace_back(1);
        for(int i = 1; i < n; i++){
            //res[i] = res[i - 1] * nums[i - 1];
            res.emplace_back(res[i - 1] * nums[i - 1]);
        }
        int temRight = 1;
        for(int i = n - 2; i >= 0; i--){
            temRight *= nums[i + 1];
            res[i] *= temRight;
        }
        return res;
    }

};


int main(){
    vector<int> sss = {1,2,3,4};
    Solution sol;
    test(sol.productExceptSelf(sss));
    return 0;
}