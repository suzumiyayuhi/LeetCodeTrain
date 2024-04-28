#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
/*
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for(int i = 0; i < n; i++){
            int cur_oil = gas[i];
            int j = i + 1;
            while(true){
                cur_oil = cur_oil - cost[(j - 1) % n];
                if(cur_oil < 0)
                    break;;
                if(j % n == i)
                    return i;
                cur_oil = cur_oil + gas[j % n];
                j++;
            }
        }
        return -1;
    }
    */

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int i = 0;
        while(i < n){
            int cur_oil = gas[i];
            int j = i % n + 1;
            while(true){
                cur_oil = cur_oil - cost[(j - 1) % n];
                if(cur_oil < 0){
                    i = j;
                    break;
                }
                if(j % n == i % n)
                    return i;
                cur_oil = cur_oil + gas[j % n];
                j++;
            }
        }
        return -1;
    }
};


int main(){
    vector<int> sss = {2,3,4};
    vector<int> aaa = {3,4,3};
    Solution sol;
    cout<<sol.canCompleteCircuit(sss,aaa);
    return 0;
}