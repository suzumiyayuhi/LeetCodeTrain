#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    string intToRoman(int num) {
		int tem;
		string context[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
		int power[13] = {1000, 900, 500 ,400,100, 90, 50 ,40 ,10, 9, 5, 4, 1};
		string str;
		for(int i = 0; i != 13; i++){
			tem = num / power[i];
			num = num % power[i];
			for(int j = 0; j < tem; j++){
				str = str + context[i];
			}
		}
		return str;
    }
};
int main(){
    Solution sol;
    cout<<sol.intToRoman(34);
    return 0;
}
