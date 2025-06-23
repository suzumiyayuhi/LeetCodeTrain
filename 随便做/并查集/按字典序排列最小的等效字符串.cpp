class UnionFind
{
    vector<int> tb;
    int n;
public:
    UnionFind(int n) : n(n)
    {
        tb.resize(n);
        for(int i = 0; i < n; i++)
            tb[i] = i;
    }

    int find(int v)
    {
        if(tb[v] != v)
            tb[v] = find(tb[v]);
        return tb[v];
    }

    void unite(int x, int y)
    {
        x = find(x);
        y = find(y);
        if(x == y)
            return;
        if(x > y)
            swap(x, y);
        tb[y] = x;
    }
};


class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        UnionFind uf(26);
        for(int i = 0; i < s1.size(); i++)
        {
            uf.unite(s1[i] - 'a', s2[i] - 'a');
        }

        string res = baseStr;
        for(int i = 0; i < res.size(); i++)
        {
            res[i] = uf.find(res[i] - 'a') + 'a';
        }
        return res;
    }
};