#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
/*
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left;
        left.emplace_back(1);
        int res = 0;
        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i - 1])
                left.emplace_back(left[i - 1] + 1);
            else
                left.emplace_back(1);
        }
        res += max(1, left[n - 1]);
        int tem = 1;
        for(int i = n - 2; i >= 0; i--){
            if(ratings[i] > ratings[i + 1]){
                tem++;
                res += max(left[i], tem);
            }
            else{
                tem = 1;
                res += left[i];
            }
        }
        return res;
    }*/
    int candy(vector<int>& ratings){
        int n = ratings.size();
        int dec_Len = 0;
        int inc_Len = 1;
        int pre = 1;
        int res = 1;
        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i - 1]){
                pre++;
                res += pre;
                inc_Len = pre;
                dec_Len = 0;
            }
            else if (ratings[i] == ratings[i - 1]){
                res++;
                pre = 1;
                dec_Len = 0;
                inc_Len = 1;
            }
            else{
                pre = 1;
                dec_Len++;
                if(dec_Len == inc_Len)
                    dec_Len++;
                res += dec_Len;

            }

        }
        return res;
    }
};


int main(){
    vector<int> sss = {1,2,3,5,4,3,2,1,4,3,2,1};
    Solution sol;
    cout<<sol.candy(sss);
    return 0;
}