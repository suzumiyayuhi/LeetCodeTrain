class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        vector<int> count1 = build(edges1, k);
        vector<int> count2 = build(edges2, k - 1);

        vector<int> res;
        int maxTree2 = 0;
        for(int i = 0; i < count2.size(); i++)
        {
            maxTree2 = max(maxTree2, count2[i]);
        }

        for(int i = 0; i < edges1.size() + 1; i++)
        {
            res.emplace_back(count1[i] + maxTree2);
            //res.emplace_back(count1[i]);
        }
        return res;
    }
    
    vector<int> build(vector<vector<int>>& edges, int k)
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
            count[i] = dfs(tree, passed, i, 0, k);
        }
        return count;
    }

    int dfs(vector<vector<int>>& tree, vector<int>& passed, int curNode, int curStep, int& k)
    {
        int res = 0;
        if(curStep > k)
            return res;
        if(passed[curNode])
            return res;
        res++;
        passed[curNode] = 1;

        for(int i = 0; i < tree[curNode].size(); i++)
        {
            res += dfs(tree, passed, tree[curNode][i], curStep + 1, k);
        }
        return res;
    }
};