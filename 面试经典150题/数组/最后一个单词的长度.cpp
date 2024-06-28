#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int res = 0;
        bool flag = false;
        for(int i = n - 1; i >= 0; i--){
            if(s[i] != ' '){
                flag = true;
                res++;
            }
            else if(flag && s[i] == ' ')
                break;
        }
        return res;
    }
};

int main(){
    Solution sol;
    string s = "ffe gg ffr qws";
    cout << sol.lengthOfLastWord(s);
    return 0;
}