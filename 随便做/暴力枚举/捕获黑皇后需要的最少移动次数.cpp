class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f)
    {
        if(a == e)
        {
            if(c != a)
                return 1;
            if(d > max(b, f) || d < min(b, f))
                return 1;
        }
        if(b == f)
        {
            if(d != b)
                return 1;
            if(c > max(a, e) || c < min(a, e))
                return 1;
        }

        if(abs(c - e) == abs(d - f))
        {
            if(abs(a - c) == abs(b - d) && a < max(c, e) && a > min(c, e) && b < max(d, f) && b > min(d, f))
            {
                return 2;
            }
            return 1;
        }

        return 2;
    }
};