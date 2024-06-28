#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    struct tool{
        vector<int> apperPosition;
    };

    bool isSubsequence(string s, string t) {
        int n = t.size();
        int m = s.size();
        if(m == 0)
            return true;
        if(n == 0)
            return false;
        tool table[255];
        for(int i = 0; i < n; i++){
            table[t[i]].apperPosition.emplace_back(i);
        }

        int prevIndex = 0;
        for(int i = 0; i < m; i++){
            if(table[s[i]].apperPosition.empty())
                return false;
            if(i == 0)
                continue;
                
            int j = 0;
            if(s[i] == s[i - 1])
                j = prevIndex + 1;
            if(j >= table[s[i]].apperPosition.size())
                    return false;

            while(table[s[i]].apperPosition[j] < table[s[i - 1]].apperPosition[prevIndex]){
                j++;
                if(j >= table[s[i]].apperPosition.size())
                    return false;
            }
            prevIndex = j;
        }
        return true;
    }
};

int main(){
    Solution sol;
    string s = "acb";
    string t = "ahbgdc";
    if(sol.isSubsequence(s, t))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    return 0;
}