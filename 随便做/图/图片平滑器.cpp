class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> res = img;
        int dir[8][2] ={1, 0,
        0, 1,
        -1, 0,
        0, -1,
        1, 1,
        -1, -1,
        1, -1,
        -1, 1};
        for(int i = 0; i < img.size(); i++)
        {
            
            for(int j = 0; j < img[0].size(); j++)
            {
                int count = 0;
                for(int k = 0; k < 8; k++)
                {
                    if(i + dir[k][0] >= 0 && i + dir[k][0] < img.size() &&
                        j + dir[k][1] >= 0 && j + dir[k][1] < img[0].size())
                    {
                        res[i][j] += img[i + dir[k][0]][j + dir[k][1]];
                        count++;
                    }
                }
                res[i][j] /= (count + 1);
            }
        }
        return res;
    }
};