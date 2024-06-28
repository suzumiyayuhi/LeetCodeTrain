#include<iostream>
#include<vector>
#include<algorithm>
#include <cstring>
using namespace std;

class Solution {
public:
/*
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int res = n;
        sort(citations.begin(), citations.end());
        for(int i = 0; i < n; i++){
            if(citations[i] < res)
                res--;
        }
        return res;
    }*/

/*
    int hIndex(vector<int>& citations){
        int n = citations.size();
        int counts[n+1];
        memset(counts, 0, sizeof(counts));
        for(int i = 0; i < n; i++){
            if(citations[i] > n)
                counts[n]++;
            else
                counts[citations[i]]++;
        }
        int res = 0;
        for(int i = n; i >= 0; i--){
            res += counts[i];
            if(res >= i)
                return i;
        }
        return 0;
    }
    */

    int hIndex(vector<int>& citations){
        int n = citations.size();
        int left = 0;
        int right = n;
        while (left < right)
        {
            int count = 0;
            int mid = (left + right + 1) / 2;
            for(int i = 0; i < n; i++){
                if(citations[i] >= mid)
                    count++;        
            }
            if(count < mid)
                right = mid - 1;
            else   
                left = mid;
        }
        return left;
    }
};

int main(){
    vector<int> sss = {3,0,6,1,5};
    Solution sol;
    cout<< sol.hIndex(sss);
    return 0;
}