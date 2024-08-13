class MagicDictionary {
public:
    vector<vector<string>> vecDic; 

    MagicDictionary() {
        vecDic = vector<vector<string>> (101, vector<string>());
    }
    
    void buildDict(vector<string> dictionary) {
        for(int i = 0; i < dictionary.size(); i++)
        {
            vecDic[dictionary[i].size()].emplace_back(dictionary[i]);
        }
    }
    
    bool search(string searchWord) {
        int sz = searchWord.size();
        vector<string> temVec = vecDic[sz];
        int dicSz = temVec.size();
        vector<int> record(dicSz, 0);
        for(int i = 0; i < sz - 1; i++)
        {
            for(int row = 0; row < dicSz; row++)
            {
                if(record[row] > 1)
                    continue;
                if(temVec[row][i] != searchWord[i])
                    record[row]++;
            }
        }

        for(int row = 0; row < dicSz; row++)
        {
            if(record[row] > 1)
                continue;
            if(temVec[row][sz - 1] == searchWord[sz - 1])
            {
                if(record[row] == 1)
                    return true;
            }
            else
            {
                if(record[row] == 0)
                    return true;
            }
        }


        return false;
    }
};