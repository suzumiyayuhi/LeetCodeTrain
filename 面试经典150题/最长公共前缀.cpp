#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string res = "";
        int j = 0;
        int i = 0;
        if(n == 0)
            return "";
        if(n == 1)
            return strs[0];
        while(true){
            i = 0;
            if(strs[i].size() <= j){
                break;
            }
            while(strs[i].size() > j){
                if(i >= n - 1)
                    break;
                if(strs[i][j] != strs[i + 1][j])
                    return res;
                i++;
            }
            res = res + strs[0][j];
            j++;
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<string> s = {""};
    cout << sol.longestCommonPrefix(s);
    return 0;
}