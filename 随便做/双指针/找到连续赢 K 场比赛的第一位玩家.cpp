class Solution
{
public:
    int findWinningPlayer(vector<int> &skills, int k)
    {
        int left = 0, right = left;
        int n = skills.size();
        int count = 0;
        while (true)
        {
            if (right + 1 >= n || left >= n)
                return left;
            while (skills[left] >= skills[right + 1])
            {
                right = right + 1;
                count++;
                if (count == k || right + 1 >= n)
                    return left;

            }
            left = right + 1;
            right = left;
            count = 1;
            if (count == k)
                return left;
        }
        return 0;
    }
};