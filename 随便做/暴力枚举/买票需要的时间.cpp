class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        int res = 0;
        int n = tickets.size();
        while (tickets[k] != 0)
        {
            for (int i = 0; i < n; i++)
            {
                if (tickets[i] == 0)
                    continue;
                else
                {
                    res++;
                    tickets[i]--;
                    if (i == k && tickets[i] == 0)
                        break;
                }
            }
        }
        return res;
    }
};