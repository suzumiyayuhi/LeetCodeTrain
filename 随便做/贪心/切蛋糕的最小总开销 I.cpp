class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        int res = 0;
        int horiTime = 1, vertiTime = 1;
        int indexHori = 0, indexVerti = 0;
        sort(horizontalCut.begin(), horizontalCut.end(), greater<int>());
        sort(verticalCut.begin(), verticalCut.end(), greater<int>());
        while(indexHori != horizontalCut.size() && indexVerti != verticalCut.size())
        {
            if(horizontalCut[indexHori] > verticalCut[indexVerti])
            {
                res += horiTime * horizontalCut[indexHori];
                indexHori++;
                vertiTime++;
            }
            else
            {
                res += vertiTime * verticalCut[indexVerti];
                indexVerti++;
                horiTime++;
            }
        }
        while(indexHori != horizontalCut.size())
        {
            res += horiTime * horizontalCut[indexHori];
            indexHori++;
        }
        while(indexVerti != verticalCut.size())
        {
            res += vertiTime * verticalCut[indexVerti];
            indexVerti++;
        }

        return res;
    }
};