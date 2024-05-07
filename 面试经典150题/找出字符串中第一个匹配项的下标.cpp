#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
/*
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        int count = 0;
        for(int i = 0; i < n;){
            if(haystack[i] == needle[count]){
                count++;
                if(count == m)
                    return i - m + 1;
                i++;
            }
            else{
                i -= count;
                if(count){
                    i++;
                    count = 0;
                }
                else
                    i++;
            }   
        }
        return -1;
    }
*/
    int strStr(string haystack, string needle){
        int n =needle.size();
        vector<int> next(n + 1, 0);
        for(int i = 0, j = 2; j < n + 1; j++){
            while(i > 0 && needle[i] != needle[j - 1])
                i = next[i];
            if(needle[i] == needle[j - 1])
                i++;
            next[j] = i;
        }
        int m = haystack.size();
        for(int i = 0, j = 0; i < m; i++){
            while(haystack[i] != needle [j] && j > 0){
                j = next[j];
            }
            if(haystack[i] == needle[j]){
                j++;
            }
            if(j == n)
                return i - n + 1;
        }
        return -1;
    }
};

int main(){
    Solution sol;
    string haystack = "mississippi", needle = "pi";
    cout << sol.strStr(haystack, needle);
    return 0;
}