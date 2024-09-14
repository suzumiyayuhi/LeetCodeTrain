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
        int minMutation(string startGene, string endGene, vector<string> &bank)
        {
            unordered_map<string, int> umDic;
            unordered_map<string, int> passed;
            bool flag = false;
            for (int i = 0; i < bank.size(); i++)
            {
                if (bank[i] == endGene)
                    flag = true;
                umDic[bank[i]] = 1;
            }
            if (!flag)
                return -1;

            queue<pair<string, int>> qq;
            qq.push(make_pair(startGene, 0));
            passed[startGene]++;
            while (!qq.empty())
            {
                string cur = qq.front().first;
                int count = qq.front().second;
                qq.pop();
                for (int i = 0; i < bank.size(); i++)
                {
                    if (passed.find(bank[i]) != passed.end())
                        continue;

                    for (int j = 0; j < 8; j++)
                    {
                        if (cur[j] != bank[i][j])
                        {
                            string tem = cur;
                            tem[j] = bank[i][j];
                            if (tem == endGene)
                                return count + 1;
                            if (umDic.find(tem) != umDic.end())
                            {
                                passed[tem] = 1;
                                qq.push(make_pair(tem, count + 1));
                            }
                        }
                    }
                }
            }

            return -1;
        }
        */
    int minMutation(string startGene, string endGene, vector<string> &bank)
    {
        unordered_set<string> usDic;
        unordered_set<string> passed;
        for (int i = 0; i < bank.size(); i++)
        {
            usDic.insert(bank[i]);
        }
        if (usDic.find(endGene) == usDic.end())
            return -1;

        queue<pair<string, int>> qq;
        qq.push(make_pair(startGene, 0));
        passed.insert(startGene);
        while (!qq.empty())
        {
            string cur = qq.front().first;
            int count = qq.front().second;
            if(cur == endGene)
                return count;
            qq.pop();
            for (int i = 0; i < 8; i++)
            {
                string tem = cur;
                if (cur[i] != 'A')
                {
                    tem[i] = 'A';
                    if (passed.find(tem) == passed.end() && usDic.find(tem) != usDic.end())
                    {
                        passed.insert(tem);
                        qq.push(make_pair(tem, count + 1));
                    }
                }
                if (cur[i] != 'G')
                {
                    tem[i] = 'G';
                    if (passed.find(tem) == passed.end() && usDic.find(tem) != usDic.end())
                    {
                        passed.insert(tem);
                        qq.push(make_pair(tem, count + 1));
                    }
                }
                if (cur[i] != 'C')
                {
                    tem[i] = 'C';
                    if (passed.find(tem) == passed.end() && usDic.find(tem) != usDic.end())
                    {
                        passed.insert(tem);
                        qq.push(make_pair(tem, count + 1));
                    }
                }
                if (cur[i] != 'T')
                {
                    tem[i] = 'T';
                    if (passed.find(tem) == passed.end() && usDic.find(tem) != usDic.end())
                    {
                        passed.insert(tem);
                        qq.push(make_pair(tem, count + 1));
                    }
                }
            }
        }

        return -1;
    }
};

int main()
{
    Solution sol;
    vector<string> bank = {"AAAACCCC","AAACCCCC","AACCCCCC"};
    string startG = "AAAAACCC";
    string endG = "AACCCCCC";
    sol.minMutation(startG, endG, bank);
    return 0;
}