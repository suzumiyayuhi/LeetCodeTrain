#include<iostream>
using namespace std;

class Solution {
public:
	bool isUpper(char c){
		 return c >= 65 && c <= 90;
	}
	
	bool isLower(char c){
		return c >= 97 && c <= 122;
	}
	
	bool isNum(char c){
		return c >= 48 && c <= 57;
	}
	
    bool isPalindrome(string s) {
		int left = 0;
		int right = s.size() - 1;
		do{
			bool leftIsUpper = isUpper(s[left]);
			bool leftIsLower = isLower(s[left]);
			bool leftIsNum = isNum(s[left]);
			bool rightIsUpper = isUpper(s[right]);
			bool rightIsLower = isLower(s[right]);
			bool rightIsNum = isNum(s[right]);
			
			while(!(leftIsUpper || leftIsLower || leftIsNum)){
				left++;
				if(left > s.size())
					break;
				leftIsUpper = isUpper(s[left]);
				leftIsLower = isLower(s[left]);
				leftIsNum = isNum(s[left]);
			}
			
			while(!(rightIsUpper || rightIsLower || rightIsNum)){
				right--;
				if(right <= 0)
					break;
				rightIsUpper = isUpper(s[right]);
				rightIsLower = isLower(s[right]);
				rightIsNum = isNum(s[right]);
			}
			
			if(left >= right)
				return true;
			
			char eLeft = s[left];
			char eRight = s[right];
			if(rightIsUpper)
				eRight += 32;
			if(leftIsUpper)
				eLeft += 32;
			
			if(eLeft != eRight){
				return false;
			}
			left++;
			right--;
		}while(left < right);
		return true;
    }
};


int main(){
	Solution sol;
	string s = "!043XjqjX043!";
	bool b = sol.isPalindrome(s);
	if(b)
		cout << "true" << endl;
	else
		cout << "false" << endl;
	return 0;
} 
