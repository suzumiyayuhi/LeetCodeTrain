class Solution {
public:
    /**/
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));
        for(int i = n - 1; i >= 0; i--)
        {
            if(questions[i][1] + i + 1> n)
            {
                dp[i][1] = max(dp[n][1], dp[n][0]) + questions[i][0];
            }
            else
            {
                dp[i][1] = max(dp[questions[i][1] + i + 1][1], dp[questions[i][1] + i + 1][0]) + questions[i][0];
            }
            dp[i][0] = max(dp[i + 1][0], dp[i + 1][1]);
        }
        return max(dp[0][0], dp[0][1]);
    }
    
    /*
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1, 0);
        for(int i = n - 1; i >= 0; i--)
        {
            if(questions[i][1] + i + 1> n)
            {
                dp[i] = dp[n]+ questions[i][0];
            }
            else
            {
                dp[i] = dp[questions[i][1] + i + 1] + questions[i][0];
            }
            dp[i] = max(dp[i], dp[i + 1]);
        }
        return dp[0];
    }
    */
};