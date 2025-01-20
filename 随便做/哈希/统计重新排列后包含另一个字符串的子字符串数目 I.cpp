class Solution {
public:
/*
    long long validSubstringCount(string word1, string word2) {
        int N = word1.size();
        int M = word2.size();

        if(M > N)
            return 0;
        vector<int> tb1(26, 0);
        vector<int> tb2(26, 0);
        long long res = 0;
        
        for(int i = 0; i < M; i++)
        {
            tb1[word1[i] - 'a']++;
            tb2[word2[i] - 'a']++;
        }
        

        for(int i = M, k = 0; i < N; i++)
        {
            vector<int> temTb1 = tb1;
            int j = i;
            while(!compare__(temTb1, tb2))
            {
                if(j >= N)
                    break;
                temTb1[word1[j] - 'a']++;
                j++;
            }
            if(compare__(temTb1, tb2))
                res += (N - j + 1);

            tb1[word1[i] - 'a']++;
            tb1[word1[k] - 'a']--;
            k++;
        }

        if(compare__(tb1, tb2))
            res++;
        return res;
    }
    */
    long long validSubstringCount(string word1, string word2)
    {
        int N = word1.size();
        int M = word2.size();

        if(M > N)
            return 0;
        vector<int> tb1(26, 0);
        vector<int> tb2(26, 0);
        long long res = 0;
        for(int i = 0; i < M; i++)
        {
            tb2[word2[i] - 'a']++;
        }

        int right = 0, left = 0;
        while(right < N)
        {
            if(compare__(tb1, tb2))
            {
                res += (N - right + 1);
                tb1[word1[left] - 'a']--;
                left++;
            }
            else
            {
                tb1[word1[right] - 'a']++;
                right++;
            }
        }

        while(compare__(tb1, tb2))
        {
            res++;
            tb1[word1[left] - 'a']--;
            left++;
        }
            
        return res;
    }


    bool compare__(vector<int>& vec1, vector<int>& vec2)
    {
        for(int i = 0; i < vec1.size(); i++)
        {
            if(vec1[i] < vec2[i])
                return false;
        }
        return true;
    }
};