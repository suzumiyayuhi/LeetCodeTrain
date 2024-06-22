#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
/*
    bool canConstruct(string ransomNote, string magazine) 
    {
        unordered_map<char, int> mmm;
        for(int i = 0; i < magazine.size(); i++)
        {
            mmm[magazine[i]]++;
        }
        for(int i = 0; i < ransomNote.size(); i++)
        {
            if(--mmm[ransomNote[i]] < 0)
                return false;
        }
        return true;
    }
*/
    bool canConstruct(string ransomNote, string magazine)
    {
        int mmm[26] = {};
        for(int i = 0; i < magazine.size(); i++)
        {
            mmm[magazine[i] - 97]++;
        }
        for(int i = 0; i < ransomNote.size(); i++)
        {
            if(--mmm[ransomNote[i] - 97] < 0)
                return false;
        }
        return true;
    }
};