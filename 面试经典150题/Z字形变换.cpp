#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
/*
    string convert(string s, int numRows) {
        int n = s.size();
        string res;
        if(numRows == 1)
            return s;
        for(int i = 0; i < n; i = i + 2 * (numRows - 1)){
            res = res + s[i];
        }
        int j = 1;
        while(j < numRows - 1){
            for(int i = 0; i <= n + numRows; i = i + 2 * (numRows - 1)){
                if(i - j >= 0 && i - j <= n - 1){
                    res = res + s[i - j];
                }
                if(i + j <= n - 1){
                    res = res + s[i + j];
                }
            }
            j++;
        }
        for(int i = numRows - 1; i < n; i = i + 2 * (numRows - 1)){
            res = res + s[i];
        }
        return res;
    }
    */
    string convert(string s, int numRows){
        int n = s.size();
        string res;
        if(numRows == 1)
            return s;
        int r = 2 * (numRows - 1);
        int rsss = n / r;
        if(n % r != 0)
            rsss++;
        for(int j = 0; j < numRows; j++){
            for(int i = 0; i < rsss; i++){
                int tem1 = i * 2 * (numRows - 1) + j;
                if(tem1 < n)
                    res += s[tem1];
                int tem2 = (i + 1) * 2 * (numRows - 1) - j;
                if(tem2 < n && j !=0 && j != numRows - 1)
                    res += s[tem2];
            }
        }
        return res;
    }
};

int main(){
    Solution sol;
    string s = "PAYPALISHIRING";
    cout << sol.convert(s, 3);
    return 0;
}