#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
/*
	int removeElement(vector<int>& nums, int val){
		for(auto i = nums.begin(); i != nums.end();){
			if(*i == val){
				i = nums.erase(i);
				continue;
			}
			i++;
		}
		return nums.size();
   }
   */
	int removeElement(vector<int>& nums, int val){
		int n = nums.size();
		for(int i = 0; i < n;){
			if(nums[i] == val){
				nums[i] = nums[--n];
                continue;
				}
			i++;
		}
		return n;
	}
};


int main(){
    Solution sol;
    vector<int> sss = {1,2,2,3,4};
    int n = sol.removeElement(sss,2);
    cout<<n<<endl;
    for(int i = 0; i < n; i++){
        cout<<sss[i]<<" ";
    }
    return 0;
}