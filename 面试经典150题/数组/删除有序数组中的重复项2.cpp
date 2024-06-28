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
    int removeDuplicates(vector<int>& nums){
        int raw_n = nums.size();
        int n = raw_n;
        int tag = 0;
        int flag = 0;
        for(int i = 1; i < raw_n; i++){
            if(nums[tag] != nums[i]){
                nums[tag + 1] = nums[i];
                tag++;
                flag = 0;
            }
            else{
                flag++;
                if(flag > 1){
                    n--;
                }
                else{
                    nums[tag + 1] = nums[i];
                    tag++;
                }
                
            }

        }
        return n;
    }
};

int main(){
    Solution sol;
    vector<int> sss = {0,0,1,1,1,2,2,3,3,4};
    //vector<int> sss = {1,1,1,1,2,2,3};
    int n = sol.removeDuplicates(sss);
    cout<<n<<endl;
    for(int i = 0; i < n; i++){
        cout<<sss[i]<<" ";
    }
    return 0;
}