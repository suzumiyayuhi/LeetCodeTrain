class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        int passId = 0;
        int k;
        for(int i = 0; i < buses.size(); i++)
        {
            k = capacity;
            while(k > 0 && passId < passengers.size())
            {
                if(buses[i] >= passengers[passId])
                {
                    k--;
                    passId++;
                }
                else
                {
                    break;
                }
            }
        }
        passId--;

        int res = k > 0 ? buses[buses.size() - 1] : passengers[passId];
        while(passId >= 0)
        {
            if(passengers[passId] == res)
            {
                res--;
                passId--;
            }
            else
                break;
        }
        return res;
    }
};