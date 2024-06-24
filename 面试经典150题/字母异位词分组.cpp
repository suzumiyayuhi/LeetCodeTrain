#include <iostream>
#include <unordered_map>
#include <vector>
#include <array>
using namespace std;

class Solution
{
public:
    /*
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            vector<unordered_map<char, int>> fff;
            vector<vector<string>> res;
            int index = 0;
            int n = strs.size();
            for(int i = 0; i < n; i++)
            {
                unordered_map<char, int> temHash;
                for(int j = 0; j < strs[i].size(); j++)
                {
                    temHash[strs[i][j]]++;
                }

                bool flag = true;
                for(int j = 0; j < index; j++)
                {
                    if(fff[j] == temHash)
                    {
                        flag = false;
                        res[j].emplace_back(strs[i]);
                    }
                }
                if(flag)
                {
                    fff.emplace_back(temHash);
                    res. emplace_back(vector<string>());
                    res[index].emplace_back(strs[i]);
                    index++;
                }

            }
            return res;
        }
        */

    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        // 自定义对 array<int, 26> 类型的哈希函数
        /*题解做法，看不懂。。。
        auto arrayHash = [fn = hash<int>{}] (const array<int, 26>& arr) -> size_t {
            return accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num) {
                return (acc << 1) ^ fn(num);
            });
        };
        unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> mp(0, arrayHash);
        */
        struct arrayHash
        {
            size_t operator() (const array<int, 26> &arr) const
            {
                size_t key = 0;
                hash<int> int_hash;
                auto iter = arr.begin();
                while(iter != arr.end())
                {
                    key += (key << 1) ^ int_hash(*iter++);
                }
                return key;
            }
        };
        unordered_map<array<int, 26>, vector<string>, arrayHash> mp;

        for(auto &str : strs)
        {
            array<int, 26> temArr{};
            int m = str.size();
            for(int i = 0; i < m; i++)
            {
                temArr[str[i] - 'a']++;
            }
            mp[temArr].emplace_back(str);
        }
        vector<vector<string>> res;

        for(auto it = mp.begin(); it != mp.end(); ++it)
        {
            res.emplace_back(it->second);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto dd = sol.groupAnagrams(strs);
    return 0;
}