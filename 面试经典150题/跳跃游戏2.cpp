#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    /*
        int jump(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int cur = 0;
        int step = nums[0];
        if(n == 1)
            return 0;
        while(cur < n - 1){
            count++;
            int temMaxPos = cur + nums[cur];
            int temCur = cur;
            for(int i = cur + 1; i <= cur + step; i++){
                if(cur + nums[i] > temMaxPos){
                    temMaxPos = cur + nums[i];
                }
            }
            cur = temMaxPos;
        }
        return count;
    }*/
    
/**/
    int jump(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int maxPos = 0;
        int up = 0;
        for(int i = 0; i < n - 1; i++){
            maxPos = max(nums[i] + i, maxPos);
            if(up == i){
                up = maxPos;
                count++;
            }
        }
        return count;
    }


};

int main(){
    vector<int> sss = {2,3,1,1,4};
    Solution sol;
    cout<< sol.jump(sss);
    return 0;
}