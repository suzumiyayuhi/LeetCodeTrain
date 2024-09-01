class Solution {
public:
/*
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        vector<int> count(1001, 0);
        for(int i = 0; i < startTime.size(); i++)
        {
            for(int j = startTime[i]; j <= endTime[i]; j++)
            {
                count[j]++;
            }
        }
        return count[queryTime];
    }
*/
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int res = 0;
        for(int i = 0; i < startTime.size(); i++)
        {
            if(startTime[i] <= queryTime && endTime[i] >= queryTime)
                res++;
        }    
        return res;
    }
};