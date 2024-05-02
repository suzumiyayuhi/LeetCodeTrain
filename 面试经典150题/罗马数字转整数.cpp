#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<unordered_map>
using namespace std;

class Solution {
	
private:
	unordered_map<char, int> roman;
	void initMap(){
		roman.insert({'I', 1});
		roman.insert({'V', 5});
		roman.insert({'X', 10});
		roman.insert({'L', 50});
		roman.insert({'C', 100});
		roman.insert({'D', 500});
		roman.insert({'M', 1000});
	}
public:
    int romanToInt(string s) {
		int n = s.size();
		int res = 0;
		initMap();
		int i = 0;
		for(; i < n - 1;){
			if(roman[s[i]]<roman[s[i + 1]]){
				res += roman[s[i + 1]] - roman[s[i]];
				i += 2;
				continue;
			}
			else{
				res += roman[s[i]];
				i++;
			}
		}
		if(i != n)
			return res + roman[s[n - 1]];
		return res;
    }
};

int main(){
    string str = "XXV";
    Solution sol;
    cout<<sol.romanToInt(str);
    return 0;
}
