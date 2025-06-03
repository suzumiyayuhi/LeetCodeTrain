class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> count1(n, -1);
        vector<int> count2(n, -1);
        build(edges, count1, node1);
        build(edges, count2, node2);

        vector<int> tb(n, -1);
        for(int i = 0; i < n; i++)
        {
            int res1 = 0x3f3f3f, res2 = 0x3f3f3f;
            bool flag = false;
            if(count1[i] != -1)
            {
                if(tb[count1[i]] == 1)
                {
                    flag = true;
                    res1 = count1[i];
                }
                    
                else
                    tb[count1[i]] = 1;
            }

            if(count2[i] != -1)
            {
                if(tb[count2[i]] == 1)
                {
                    flag = true;
                    res2 = count2[i];
                }
                else
                    tb[count2[i]] = 1;
            }

            if(flag)
                return min(res1, res2);
            
        }
        return -1;
    }
    
    void build(vector<int>& edges, vector<int>& count, int node)
    {
        vector<int> passed(edges.size(), 0);
        dfs(edges, count, passed, node, 0);
    }

    void dfs(vector<int>& edges, vector<int>& count, vector<int>& passed, int curNode, int depth)
    {
        if(curNode == -1)
            return;
        if(passed[curNode])
            return;
        passed[curNode] = 1;
        count[depth] = curNode;

        dfs(edges, count, passed, edges[curNode], depth + 1);
    }
};