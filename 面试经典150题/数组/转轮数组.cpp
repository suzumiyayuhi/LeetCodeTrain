#include<iostream>
#include<vector>
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
    void rotate(vector<int>& nums, int k) {
        vector<int> nums2 = nums;
        int n = nums.size();
        int rk = k % n;
        if(n == 1 || rk == 0)
            return;
        for(int i = 0; i < rk; i++){
            nums[i] = nums2[n - rk + i];
        }
        for(int i = rk; i < n; i++){
            nums[i] = nums2[i - rk];
        }
    }*/

/*
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int rk1 = k % n;
        int rk2 = rk1;
        int count = 0;
        int tag = 0;
        if(n == 1 || k == 0)
        	return;
        while(true){
            count++;
            int tem = nums[tag];
            nums[tag] = nums[(tag + rk2) % n];
            nums[(tag + rk2) % n] = tem;
            rk2 += rk1;
            rk2 = rk2 % n;
            if(count == n - 1)
                break;
            if(rk2 == 0)
            	tag++;
        }
    }
    */
    
    void temReverse(vector<int>& nums, int low, int up){
    	while(low < up){
    		int tem = nums[low];
    		nums[low++] = nums[up];
    		nums[up--] = tem;
		}
	}
    
    void rotate(vector<int>& nums, int k){
    	int n = nums.size();
		temReverse(nums, 0, n - 1);
		temReverse(nums, 0, k % n - 1);
		temReverse(nums, k % n, n - 1); 
	}
};


int main(){
    Solution sol;
    vector<int> sss = {1,2,3,4,5,6};
    sol.rotate(sss,4);
    test(sss);
    return 0;
}
