#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int start = 0;
        int end = 0;
        int dic[256] = {0};
        int res = 0;

        while(end < n){
            if(dic[s[end]] == 0){
                res = max(res, end - start + 1);
                dic[s[end]] = end + 1;
                end++;
            }
            else{
                int tem = start;
                start = dic[s[end]];
                while(tem < start){
                    dic[s[tem++]] = 0;
                }
                dic[s[end]] = end + 1;
                end++;
            }
        }
        return res;
    }
};


int main(){
    Solution sol;
    string s = "abcabcbb";
    cout<<sol.lengthOfLongestSubstring(s);
    return 0;
}