#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int res = 0;
        int temLow = prices[0];
        for(int i = 0; i < n; i++){
            if(prices[i] < temLow){
                temLow = prices[i];
            }
            else{
                res += prices[i] - temLow;
                temLow = prices[i];
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