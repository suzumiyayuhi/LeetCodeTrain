#include<iostream>
#include<vector>
using namespace std;

void test(vector<int> sss){
    for(int i = 0; i < sss.size(); i++){
        cout<<sss[i]<<" ";
    }
    cout<<endl;
}

class Solution{
public:
    /*int removeDuplicates(vector<int>& nums) {
        int raw_n = nums.size();
        int n = nums.size();
        for(int i = 0; i < n - 1; i++){
            int tag1 = i;
            int tag2 = i + 1;
            bool flag = false;
            while(nums[tag1] == nums[tag2]){
                tag2++;
                n--;
                flag = true;
                if(tag2 >= raw_n)
                    break;
                
            }
            if(flag){
                for(int j = 1; tag2 + j - 1 < raw_n; j++){
                    nums[tag1 + j] = nums[tag2 + j - 1];
                }
                raw_n = n;
            }
            //test(nums);
        }
        return n;
    }*/

/*
    int removeDuplicates(vector<int>& nums){
        int raw_n = nums.size();
        int n = raw_n;
        int und = 0;
        for(int i = 1; i < raw_n; i++){
            if(nums[und] == nums[i]){
                n--;
            }
            if(nums[und] != nums[i]){
                nums[und + 1] = nums[i];
                und++;
            }
        }
        return n;
    }
    */

    int removeDuplicates(vector<int>& nums){
        int raw_n = nums.size();
        int n = raw_n;
        int und = 0;
        for(int i = 1; i < raw_n; i++){
            if(nums[und] != nums[i]){
                nums[und + 1] = nums[i];
                und++;
                continue;
            }
            n--;
        }
        return n;
    }

};



int main(){
    Solution sol;
    vector<int> sss = {0,0,1,1,1,2,2,3,3,4};
    int n = sol.removeDuplicates(sss);
    cout<<n<<endl;
    for(int i = 0; i < n; i++){
        cout<<sss[i]<<" ";
    }
    return 0;
}