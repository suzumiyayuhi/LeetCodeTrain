#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

class Solution
{
public:
    /*
        int ladderLength(string beginWord, string endWord, vector<string> &wordList)
        {
            unordered_map<string, vector<string>> um;
            unordered_map<string, int> passed;
            int flag = 0;
            for (int i = 0; i < wordList.size(); i++)
            {
                if (wordList[i] == endWord)
                    flag++;
                for (int j = 0; j < wordList.size(); j++)
                {
                    if(j == i)
                        continue;
                    if (canTrans(wordList[i], wordList[j]))
                        um[wordList[i]].emplace_back(wordList[j]);
                }
            }
            if (flag != 1)
                return 0;

            queue<string> q;
            queue<int> subQ;
            for (int i = 0; i < wordList.size(); i++)
            {
                if(wordList[i] == beginWord)
                {
                    continue;
                    passed[wordList[i]] = 1;
                }
                if (canTrans(beginWord, wordList[i]))
                {
                    passed[wordList[i]] = 1;
                    q.push(wordList[i]);
                    subQ.push(2);
                }
            }

            while (!q.empty())
            {
                string curStr = q.front();
                int res = subQ.front();
                q.pop();
                subQ.pop();
                if (curStr == endWord)
                    return res;

                for (auto temStr : um[curStr])
                {

                    if (passed[temStr])
                        continue;
                    if (!canTrans(temStr, curStr))
                        continue;
                    passed[temStr] = 1;
                    q.push(temStr);
                    subQ.push(res + 1);
                }
            }
            return 0;
        }
    */

    /*
        int ladderLength(string beginWord, string endWord, vector<string> &wordList)
        {
            unordered_map<string, vector<int>> um;
            unordered_map<int, int> passed;
            int flag = 0;
            for (int i = 0; i < wordList.size(); i++)
            {
                if (wordList[i] == endWord)
                    flag++;
                for (int j = 0; j < wordList.size(); j++)
                {
                    if (j == i)
                        continue;
                    if (canTrans(wordList[i], wordList[j]))
                        um[wordList[i]].emplace_back(j);
                }
            }
            if (flag != 1)
                return 0;

            queue<int> q;
            queue<int> subQ;
            for (int i = 0; i < wordList.size(); i++)
            {
                if (wordList[i] == beginWord)
                {
                    continue;
                    passed[i] = 1;
                }
                if (canTrans(beginWord, wordList[i]))
                {
                    passed[i] = 1;
                    q.push(i);
                    subQ.push(2);
                }
            }

            while (!q.empty())
            {
                string curStr = wordList[q.front()];
                int res = subQ.front();
                q.pop();
                subQ.pop();
                if (curStr == endWord)
                    return res;

                for (int tem : um[curStr])
                {
                    string &temStr = wordList[tem];
                    if (passed[tem])
                        continue;
                    if (!canTrans(temStr, curStr))
                        continue;
                    passed[tem] = 1;
                    q.push(tem);
                    subQ.push(res + 1);
                }
            }
            return 0;
        }
    */

    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        int n = wordList.size();
        vector<vector<int>> edges(n, vector<int>());
        vector<int> passed(n, 0);
        int endIndex = -1;

        for (int i = 0; i < wordList.size(); i++)
        {
            if (wordList[i] == endWord)
                endIndex = i;
            for (int j = i; j < wordList.size(); j++)
            {
                if (j == i)
                    continue;
                if (canTrans(wordList[i], wordList[j]))
                {
                    edges[i].emplace_back(j);
                    edges[j].emplace_back(i);
                }
            }
        }
        if (endIndex == -1)
            return 0;

        queue<int> q;
        queue<int> subQ;
        for (int i = 0; i < wordList.size(); i++)
        {
            if (wordList[i] == beginWord)
            {
                continue;
                passed[i] = 1;
            }
            if (canTrans(beginWord, wordList[i]))
            {
                passed[i] = 1;
                q.push(i);
                subQ.push(2);
            }
        }

        while (!q.empty())
        {
            int curId = q.front();
            int res = subQ.front();
            q.pop();
            subQ.pop();
            if (curId == endIndex)
                return res;

            for (int tem : edges[curId])
            {
                if (passed[tem])
                    continue;
                passed[tem] = 1;
                q.push(tem);
                subQ.push(res + 1);
            }
        }
        return 0;
    }

    bool canTrans(string &str1, string &str2)
    {
        int flag = 0;
        for (int i = 0; i < str1.size(); i++)
        {
            if (str1[i] != str2[i])
            {
                if (++flag > 1)
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    vector<string> ss = {"hot", "dog", "dot"};
    Solution sol;
    sol.ladderLength("hot", "dog", ss);
    return 0;
}