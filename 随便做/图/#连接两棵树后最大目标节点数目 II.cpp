class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        vector<int> color1(edges1.size() + 1, 0);
        vector<int> color2(edges2.size() + 1, 0);
        vector<int> count1 = build(edges1, color1);
        vector<int> count2 = build(edges2, color2);

        vector<int> res;
        for(int i = 0; i < edges1.size() + 1; i++)
        {
            res.emplace_back(count1[color1[i]] + max(count2[0], count2[1]));
        }
        return res;
    }

    vector<int> build(vector<vector<int>>& edges, vector<int>& color)
    {
        int n = edges.size() + 1;
        vector<vector<int>> tree(n, vector<int>());
        for(int i = 0; i < edges.size(); i++)
        {
            tree[edges[i][0]].emplace_back(edges[i][1]);
            tree[edges[i][1]].emplace_back(edges[i][0]);
        }

        int evenNum = dfs(tree, -1, 0, 0, color);
        return {evenNum, n - evenNum};
    }

    int dfs(vector<vector<int>>& tree, int parentNode, int curNode, int curStep, vector<int>& color)
    {
        int res = 1 - curStep % 2;
        color[curNode] = curStep % 2;

        for(int i = 0; i < tree[curNode].size(); i++)
        {
            if(tree[curNode][i] == parentNode)
                continue;
            res += dfs(tree, curNode, tree[curNode][i], curStep + 1, color);
        }
        return res;
    }
};

/*
class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        vector<int> count1 = build(edges1, false);
        vector<int> count2 = build(edges2, true);

        vector<int> res;
        int maxTree2 = 0;
        for(int i = 0; i < count2.size(); i++)
        {
            maxTree2 = max(maxTree2, count2[i]);
        }

        for(int i = 0; i < edges1.size() + 1; i++)
        {
            res.emplace_back(count1[i] + maxTree2);
        }
        return res;
    }

    vector<int> build(vector<vector<int>>& edges, bool isOdd)
    {
        int n = edges.size() + 1;
        vector<vector<int>> tree(n, vector<int>());
        for(int i = 0; i < edges.size(); i++)
        {
            tree[edges[i][0]].emplace_back(edges[i][1]);
            tree[edges[i][1]].emplace_back(edges[i][0]);
        }
        
        vector<int> count(n, 0);
        for(int i = 0; i < n; i++)
        {
            vector<int> passed(n, 0);
            count[i] = dfs(tree, passed, i, 0, isOdd);
        }
        return count;
    }

    int dfs(vector<vector<int>>& tree, vector<int>& passed, int curNode, int curStep, bool isOdd)
    {
        int res = 0;
        if(passed[curNode])
            return res;
        if(!(isOdd ^ (curStep % 2)))
            res++;

        passed[curNode] = 1;

        for(int i = 0; i < tree[curNode].size(); i++)
        {
            res += dfs(tree, passed, tree[curNode][i], curStep + 1, isOdd);
        }
        return res;
    }
};
*/