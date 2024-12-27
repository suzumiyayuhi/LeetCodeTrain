class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int res = 0;
        int day = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        while(day < apples.size())
        {
            pq.push({day + days[day], apples[day]});

            pair<int, int> tem = pq.top();
            pq.pop();
            while((tem.first == day || tem.second == 0) && !pq.empty())
            {
                tem = pq.top();
                pq.pop();
            }
            
            if(tem.second != 0 && tem.first != day)
            {
                tem.second--;
                res++;
                pq.push(tem);
            }
            
            day++;
        }

        while(!pq.empty())
        {
            pair<int, int> tem = pq.top();
            pq.pop();
            if(tem.first - day <= 0 || tem.second <= 0)
                continue;

            int cost = min(tem.first - day, tem.second);
            res += cost;
            day += cost;
        }

        return res;
    }
};