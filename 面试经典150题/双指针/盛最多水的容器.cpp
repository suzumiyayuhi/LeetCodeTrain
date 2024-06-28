#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int res = min(height[left], height[right]) * (right - left);
        while(left < right){
            int leftD = height[left + 1] - height[left];
            int rightD = height[right - 1] - height[right];
            if(height[left] >= height[right]){
                right--;
                if(rightD <= 0)
                    continue;
            }
                
            else{
                left++;
                if(leftD <= 0)
                    continue;
            }
                
            res = max(res, min(height[left], height[right]) * (right - left));
        }
        return res;
    }
};

int main(){
    Solution sol;
    //vector<int> height = {1,8,6,2,5,4,8,25,7};
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << sol.maxArea(height) << endl;
    return 0;
}