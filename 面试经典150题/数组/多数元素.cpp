#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    /*int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hashmm;
        int cnt = 0;
        int maj = 0;
        for(auto i = nums.begin(); i != nums.end(); i++){
            ++hashmm[*i];
            if(hashmm[*i] > cnt){
                cnt = hashmm[*i];
                maj = *i;
            }
        }
        return maj;
    }*/

/*
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        return subFindMaj1(nums, n - 1, 0);
    }

    int subFindMaj1(vector<int>& nums, int up, int low){
        if(up == low){
            return nums[up];
        }
        int mid = (up + low) / 2;
        int left = subFindMaj1(nums, mid, low);
        int right = subFindMaj1(nums, up, mid + 1);
        if(subFindMaj2(nums, 0, left, up, low) > (up - low + 1) / 2){
            return left;
        }
        if(subFindMaj2(nums, 0, right, up, low) > (up - low + 1) / 2){
            return right;
        }
        return 0x3f3f3f3f;
    }

    int subFindMaj2(vector<int>& nums,int count, int target, int up, int low){
        for(int i = low; i <= up; i++){
            if(target == nums[i])
                count++;
        }
        return count;
    }
/**/
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int target = 0;
        int count = 0;
        for(int i = 0; i < n; i++){
            if(count == 0){
                target = nums[i];
                count++;
                continue;
            }
            if(target == nums[i]){
                count++;
            }
            else{
                count--;
            }
        }
        return target;
    }
};

int main(){
    Solution sol;
    vector<int> sss = {8,7,8,7,7};
    int n = sol.majorityElement(sss);
    cout<<n<<endl;
    return 0;
}