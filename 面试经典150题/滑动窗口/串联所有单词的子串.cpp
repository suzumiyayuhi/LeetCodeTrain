#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
	/*
	vector<int> findSubstring(string s, vector<string>& words) {
		unordered_map<string, int> hashWords, temHashWords;
		for (int i = 0; i < words.size(); i++)
		{
			hashWords[words[i]]++;
		}
		vector<int> res;
		int mm = words.size();
		int n = s.size();
		int m = words[0].size();
		for (int i = 0; i < n - m * mm + 1; i++)
		{
			temHashWords = hashWords;
			for (int j = 0; j < mm; j++)
			{
				string temStr = s.substr(i + j * m, m);


				if (temHashWords[temStr] != 0)
				{
					temHashWords[temStr]--;
					if (j == mm - 1)
					{
						res.emplace_back(i);

					}
				}
				else
				{
					break;
				}
			}
		}
		return res;
	}
	*/
	/*
	vector<int> findSubstring(string s, vector<string>& words)
	{
		unordered_map<string, int> hashWords, temHashWords;
		for (int i = 0; i < words.size(); i++)
		{
			hashWords[words[i]]++;
		}
		vector<int> res;
		int mm = words.size();
		int n = s.size();
		int m = words[0].size();
		for (int i = 0; i < m; i++)
		{
			for (int j = i; j < n - m * mm + 1; j += m)
			{
				temHashWords = hashWords;
				unordered_map<string, int> firstWordsIndex;
				int temss = 0;
				for (int k = 0; k < mm; k++)
				{

					string temStr = s.substr(j + k * m, m);
					if (temHashWords.find(temStr) == temHashWords.end())
					{
						j += k  * m;
						temHashWords = hashWords;
						break;
					}
					else if (temHashWords[temStr] == 0)
					{
						j = firstWordsIndex[temStr];
						break;
					}
					else if (temHashWords[temStr])
					{
						if (firstWordsIndex.find(temStr) == firstWordsIndex.end())
							firstWordsIndex[temStr] = j + k * m;
						temHashWords[temStr]--;
						if (k == mm - 1)
						{
							res.emplace_back(j);
							if (j >= n - m * mm + 1)
								break;
							string temStr2 = s.substr(j, m);
							k--;
							j += m;
							temss++;
							firstWordsIndex.erase(temStr2);
							temHashWords[temStr2]++;

						}
					}


				}
			}
		}
		return res;
	}
	*/
	/*
	vector<int> findSubstring(string s, vector<string>& words)
	{
		unordered_map<string, int> hashWords, temHashWords;
		for (int i = 0; i < words.size(); i++)
		{
			hashWords[words[i]]++;
		}
		vector<int> res;
		int mm = words.size();
		int n = s.size();
		int m = words[0].size();
		for (int i = 0; i < m; i++)
		{
			for (int j = i; j < n - m * mm + 1; j += m)
			{
				unordered_map<string, int> firstWordsIndex;
				for (int k = 0; k < mm; k++)
				{

					string temStr = s.substr(j + k * m, m);
					if (hashWords[temStr] == 0)
					{
						j += k * m;
						temHashWords.clear();
						break;
					}
					else if (temHashWords[temStr] == hashWords[temStr])
					{
						j = firstWordsIndex[temStr];
						temHashWords.clear();
						break;
					}
					else if (temHashWords[temStr] != hashWords[temStr])
					{
						if (firstWordsIndex.find(temStr) == firstWordsIndex.end())
							firstWordsIndex[temStr] = j + k * m;
						temHashWords[temStr]++;
						if (k == mm - 1)
						{
							res.emplace_back(j);
							if (j >= n - m * mm + 1)
								break;
							string temStr2 = s.substr(j, m);
							k--;
							j += m;

							firstWordsIndex.erase(temStr2);
							temHashWords[temStr2]--;

						}
					}


				}
			}

		}
		return res;
	}
	*/

vector<int> findSubstring(string s, vector<string>& words)
{
	unordered_map<string, int> hashWords, temHashWords;
	for (int i = 0; i < words.size(); i++)
	{
		hashWords[words[i]]++;
	}
	vector<int> res;
	int mm = words.size();
	int n = s.size();
	int m = words[0].size();
	for (int i = 0; i < m; i++)
	{
		for (int j = i; j < n - m * mm + 1; j += m)
		{
			for (int k = 0; k < mm; k++)
			{

				string temStr = s.substr(j + k * m, m);
				if (hashWords[temStr] == 0)
				{
					j += k * m;
					temHashWords.clear();
					break;
				}
				else if (temHashWords[temStr] == hashWords[temStr])
				{
					int temIndex = 0;
					while (temStr != s.substr(j + (temIndex++) * m, m));
					j += (--temIndex) * m;
					temHashWords.clear();
					break;
				}
				else if (temHashWords[temStr] != hashWords[temStr])
				{
					temHashWords[temStr]++;
					if (k == mm - 1)
					{
						res.emplace_back(j);
						if (j >= n - m * mm + 1)
							break;
						string temStr2 = s.substr(j, m);
						k--;
						j += m;

						temHashWords[temStr2]--;

					}
				}


			}
		}

	}
	return res;
}

};

int main()
{
	string s = "barfoothefoobarman";
	vector<string> words;
	words.emplace_back("bar");
	words.emplace_back("foo");


	Solution sol;
	sol.findSubstring(s, words);
	return 0;
}