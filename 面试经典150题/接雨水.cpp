#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;


class Solution {
public:
/*
    int trap(vector<int>& height) {
        int n = height.size();
        int res = 0;
        vector<int> leftMax;
        leftMax.emplace_back(height[0]);
        for(int i = 1; i < n;i ++){
            int tem = max(leftMax[i - 1], height[i]);
            leftMax.emplace_back(tem);
        }
        int rightMax = height[n - 1];
        for(int i = n - 2; i >= 0; i--){
            rightMax = max(rightMax, height[i]);
            if(height[i] < leftMax[i] && height[i] < rightMax){
                int tem = min(leftMax[i], rightMax) - height[i];
                res += tem;
            }
        }
        return res;
    }*/

    int trap(vector<int>& height){
        int n = height.size();
        int leftMax = height[0];
        int rightMax = height[n - 1];
        int leftInd = 0;
        int rightInd = n - 1;
        while(leftInd < rightInd){
            
        }
    }
};

int main(){
    vector<int> sss = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution sol;
    cout<<sol.trap(sss);
    return 0;
}