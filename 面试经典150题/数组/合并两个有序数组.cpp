#include<iostream>
#include<vector>
using namespace std;
 
 
class Solution {
public:
	/* 
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		if(n == 0 )
			return;
		if(m == 0){
			nums1 = nums2;
			return;
		}
				
		int i = m - 1;
		int j = n - 1;
		while(i >= 0 && j >= 0)
		{
			if(nums1[i] < nums2[j]){
				nums1[i + j + 1] = nums2[j];
				j--;
			} 		
			else{
				nums1[i + j + 1] = nums1[i];
				i--;
			}
		}
		if(i < 0){
			while(j >= 0){
				nums1[j] = nums2[j];
				j--;
			}
		}
	}
*/

	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i = m - 1;
		int j = n - 1;
		while(i >= 0 && j >= 0)
		{
			if(nums1[i] < nums2[j]){
				nums1[i + j + 1] = nums2[j];
				j--;
			} 		
			else{
				nums1[i + j + 1] = nums1[i];
				i--;
			}
		}
		if(i < 0){
			while(j >= 0){
				nums1[j] = nums2[j];
				j--;
			}
		}
	}
};



int main(){
	Solution sol;
	vector<int> v1 = {1,2,3,0,0,0};
	vector<int> v2 = {2,5,6};
	int m1 = 3;
	int n1 = 3;
	sol.merge(v1,m1,v2,n1);
	for(int i = 0; i != v1.size(); i++)
		cout << v1[i] << " ";
	return 0;
}
