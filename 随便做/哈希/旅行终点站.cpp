class Solution {
public:
    string destCity(vector<vector<string>>& paths) 
    {
        unordered_map<string, string> um;
        if(paths.size() == 1)
            return paths[0][1];
        for(int i = 0; i < paths.size(); i++)
        {
            um[paths[i][0]] = paths[i][1];
        }

        string tem = paths[0][1];
        while(um.find(tem) != um.end())
        {
            tem = um[tem];
        }
        return tem;
    }
};