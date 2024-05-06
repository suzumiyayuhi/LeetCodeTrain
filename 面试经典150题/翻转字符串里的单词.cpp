#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
/*
    string reverseWords(string s) {
        int n = s.size();
        vector<string> loot;
        string tem;
        for(int i = 0; i < n; i++){
            if(s[i] == ' '){
                if(!tem.empty())
                    loot.emplace_back(tem);
                tem = "";
                continue;
            }
            tem = tem + s[i];
        }
        if(!tem.empty())
            loot.emplace_back(tem);
        string res = "";
        n = loot.size();
        for(int i = n - 1; i >= 0; i--){
            res = res + loot[i];
            if(i != 0)
                res = res + " ";
        }
        return res;
    }
    */

   string reverseWords(string s){
        int n = s.size();
        string res, tem;
        int i = 0;
        int j = n - 1;
        for(; j >= 0; j--){
            if(s[j] != ' ')
                break;
        }
        for(; i <= j; i++){
            if(s[i] == ' '){
                if(!tem.empty()){
                    res = " " + tem +  res;
                    tem = "";
                }
            }
            else{
                tem = tem + s[i];
            }
                
        }
        if(!tem.empty())
            res = tem + res;
        return res;
   }
};

int main(){
    Solution sol;
    string s = "the sky is   blue ";
    cout << sol.reverseWords(s);
    return 0;
}