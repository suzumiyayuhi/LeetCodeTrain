#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int res = 0;
        int temRes = res;
        int temLow = prices[0];
        for(int i = 1; i < n; i++){
            if(temLow > prices[i]){
                temLow = prices[i];
            }
            else{
                temRes = prices[i] - temLow;
                if(temRes > res)
                    res = temRes;
            }
        }
        return res;
    }
};

int main(){
    vector<int> sss = {7,1,5,3,6,4};
    Solution sol;
    cout<< sol.maxProfit(sss);
    return 0;
}