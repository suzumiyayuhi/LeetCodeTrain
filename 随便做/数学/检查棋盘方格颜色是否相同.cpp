class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) 
    {
        int d1 = abs(coordinate1[0] - coordinate2[0]);
        int d2 = abs(coordinate1[1] - coordinate2[1]);
        if(d1 % 2)
        {
            if(d2 % 2)
                return true;
            return false;
        }
        else
        {
            if(d2 % 2)
                return false;
            return true;
        }
    }
};