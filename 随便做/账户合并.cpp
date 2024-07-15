#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <numeric>
#include <unordered_map>
using namespace std;

class UnionFind
{
    vector<int> vec_indices;
public:
    UnionFind(int n)
    {
        vec_indices.resize(n);
        iota(vec_indices.begin(), vec_indices.end(), 0);
    }

    void unionSet(int index1, int index2)
    {
        vec_indices[findParentIndex(index2)] = findParentIndex(index1);
    }

    int findParentIndex(int index)
    {
        if(vec_indices[index] != index)
        {
            vec_indices[index] = findParentIndex(vec_indices[index]);
        }
        return vec_indices[index];
    }
};

class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        unordered_map<string, int> emailToIndex;
        unordered_map<string, string> emailToName;
        int count = 0;
        for(int i = 0; i < accounts.size(); i++)
        {
            for(int j = 1; j <accounts[i].size(); j++)
            {
                if(emailToIndex.find(accounts[i][j]) == emailToIndex.end())
                {
                    emailToIndex[accounts[i][j]] = count++;
                    emailToName[accounts[i][j]] = accounts[i][0];
                }
            }
        }

        UnionFind findSet(count);
        for(int i = 0; i < accounts.size(); i++)
        {
            int firstIndex = emailToIndex[accounts[i][1]];
            for(int j = 2; j < accounts[i].size(); j++)
            {
                int nextIndex = emailToIndex[accounts[i][j]];
                findSet.unionSet(firstIndex, nextIndex);
            }
        }

        unordered_map<int, vector<string>> indexToEmails;
        for(auto email_index = emailToIndex.begin(); email_index != emailToIndex.end(); email_index++)
        {
            int parentIndex = findSet.findParentIndex(email_index->second);
            indexToEmails[parentIndex].emplace_back(email_index->first);
        }

        vector<vector<string>> merged;
        for(auto index_emails = indexToEmails.begin(); index_emails != indexToEmails.end(); index_emails++)
        {
            string name = emailToName[index_emails->second[0]];
            vector<string> temAccount;
            temAccount.emplace_back(name);
            for(int j = 0; j < index_emails->second.size(); j++)
            {
                temAccount.emplace_back(index_emails->second[j]);
            }
            merged.emplace_back(temAccount);
        }

        return merged;
    }
};

int main()
{
    Solution sol;
    vector<vector<string>> accounts = {{"John", "johnsmith@mail.com", "john_newyork@mail.com"},
                                       {"John", "johnsmith@mail.com", "john00@mail.com"},
                                       {"Mary", "mary@mail.com"},
                                       {"John", "johnnybravo@mail.com"}};
    auto ss = sol.accountsMerge(accounts);
    for (int i = 0; i < ss.size(); i++)
    {
        for (int j = 0; j < ss[i].size(); j++)
        {
            cout << ss[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}