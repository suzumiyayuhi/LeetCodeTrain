class Solution
{
public:
    /*
        int countGoodNodes(vector<vector<int>> &edges)
        {
            unordered_map<int, vector<int>> um;
            int n = 0;
            for (int i = 0; i < edges.size(); i++)
            {
                um[edges[i][0]].emplace_back(edges[i][1]);
                um[edges[i][1]].emplace_back(edges[i][0]);
                n = max(n, edges[i][0]);
                n = max(n, edges[i][1]);
            }

            vector<int> passed(n + 1, 0);
            int res = 0;
            stack<int> st;
            st.push(0);
            while(!st.empty())
            {
                int root = st.top();
                st.pop();
                passed[root] = 1;
                for(int i = 0; i < um[root].size(); i++)
                {
                    if(passed[um[root][i]])
                        continue;
                    st.push(um[root][i]);
                }
                if(um[root].size() == 1 || (um[root].size() == 2 && root))
                {
                    res++;
                    continue;;
                }

                int count1 = 0, count2 = 0;
                bool flag = true;
                for(int i = 0; i < um[root].size(); i++)
                {
                    if(count1)
                    {
                        subCount(count2, um, um[root][i], passed);
                        if(count1 != count2)
                        {
                            flag = false;
                            break;
                        }
                        count2 = 0;
                    }
                    else
                    {
                        subCount(count1, um, um[root][i], passed);
                    }
                }
                if(flag)
                    res++;
            }
            return res;
        }

        void subCount(int &count, unordered_map<int, vector<int>> &um, int root, vector<int> passed)
        {
            if(passed[root])
                return;
            count++;
            passed[root] = 1;
            for (int i = 0; i < um[root].size(); i++)
            {
                subCount(count, um, um[root][i], passed);
            }
        }
        */
       /*
    int countGoodNodes(vector<vector<int>> &edges)
    {
        unordered_map<int, vector<int>> um;
        int n = edges.size() + 1;
        for (int i = 0; i < edges.size(); i++)
        {
            um[edges[i][0]].emplace_back(edges[i][1]);
            um[edges[i][1]].emplace_back(edges[i][0]);
        }

        vector<int> childrenSize(n + 1, 0);
        getChildSize(0, um, -1, childrenSize);
        vector<int> passed(n + 1, 0);
        int res = 0;
        stack<int> st;
        st.push(0);
        while (!st.empty())
        {
            int root = st.top();
            st.pop();
            passed[root] = 1;
            for (int i = 0; i < um[root].size(); i++)
            {
                if (passed[um[root][i]])
                    continue;
                st.push(um[root][i]);
            }
            if (um[root].size() == 1 || (um[root].size() == 2 && root))
            {
                res++;
                continue;
            }

            int count1 = 0, count2 = 0;
            bool flag = true;
            for (int i = 0; i < um[root].size(); i++)
            {
                if (passed[um[root][i]])
                    continue;
                if (!count1)
                {
                    count1 = childrenSize[um[root][i]] + 1;
                    continue;
                }
                count2 = childrenSize[um[root][i]] + 1;
                if(count1 != count2)
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
                res++;
        }
        return res;
    }

    int getChildSize(int root, unordered_map<int, vector<int>> &um, int parent, vector<int> &childrenSize)
    {
        int sum = 0;
        for (int i = 0; i < um[root].size(); i++)
        {
            if (um[root][i] == parent)
                continue;
            childrenSize[um[root][i]] = getChildSize(um[root][i], um, root, childrenSize);
            sum += childrenSize[um[root][i]] + 1;
        }
        childrenSize[root] = sum;
        return sum;
    }
*/
    int countGoodNodes(vector<vector<int>> &edges)
    {
        int n = edges.size() + 1;
        vector<vector<int>> um(n, vector<int>());
        
        for (int i = 0; i < edges.size(); i++)
        {
            um[edges[i][0]].emplace_back(edges[i][1]);
            um[edges[i][1]].emplace_back(edges[i][0]);
        }

        vector<int> childrenSize(n + 1, 0);
        getChildSize(0, um, -1, childrenSize);
        vector<int> passed(n + 1, 0);
        int res = 0;
        stack<int> st;
        st.push(0);
        while (!st.empty())
        {
            int root = st.top();
            st.pop();
            passed[root] = 1;
            for (int i = 0; i < um[root].size(); i++)
            {
                if (passed[um[root][i]])
                    continue;
                st.push(um[root][i]);
            }
            if (um[root].size() == 1 || (um[root].size() == 2 && root))
            {
                res++;
                continue;
            }

            int count1 = 0, count2 = 0;
            bool flag = true;
            for (int i = 0; i < um[root].size(); i++)
            {
                if (passed[um[root][i]])
                    continue;
                if (!count1)
                {
                    count1 = childrenSize[um[root][i]] + 1;
                    continue;
                }
                count2 = childrenSize[um[root][i]] + 1;
                if(count1 != count2)
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
                res++;
        }
        return res;
    }

    int getChildSize(int root, vector<vector<int>> &um, int parent, vector<int> &childrenSize)
    {
        int sum = 0;
        for (int i = 0; i < um[root].size(); i++)
        {
            if (um[root][i] == parent)
                continue;
            childrenSize[um[root][i]] = getChildSize(um[root][i], um, root, childrenSize);
            sum += childrenSize[um[root][i]] + 1;
        }
        childrenSize[root] = sum;
        return sum;
    }
};