#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    void fullJustify2(vector<string> &temRowStr, vector<string> &res, int &currentSize, int maxWidth, bool final){
        int space = maxWidth - currentSize;
        if(final){
            if(temRowStr.size() > 1){
                int spaceCount1 = space / (temRowStr.size() - 1);
                int spaceCount2 = space % (temRowStr.size() - 1);
                for(int j = 0; j < temRowStr.size() - 1; j++){
                    for(int k = 0; k < spaceCount1; k++){
                        temRowStr[j] += " ";
                    }
                }
                string currentRow = "";
                for(int j = 0; j < temRowStr.size(); j++){
                    currentRow += temRowStr[j];
                }
                int temCurSize = currentRow.size();
                for(int k = 0; k < maxWidth - temCurSize; k++)
                    currentRow += " ";
                res.emplace_back(currentRow);
                temRowStr.clear();
            }
            else{
                int spaceCount1 = maxWidth - currentSize;
                for(int k = 0; k < spaceCount1; k++){
                    temRowStr[0] += " ";
                }
                res.emplace_back(temRowStr[0]);
                temRowStr.clear();                
            }
            return;
        }

        if(temRowStr.size() > 1){
            int spaceCount1 = space / (temRowStr.size() - 1);
            int spaceCount2 = space % (temRowStr.size() - 1);
            for(int j = 0; j < temRowStr.size() - 1; j++){
                for(int k = 0; k < spaceCount1; k++){
                    temRowStr[j] += " ";
                }
                if(spaceCount2){
                    spaceCount2--;
                    temRowStr[j] += " ";
                }
            }
            string currentRow = "";
            for(int j = 0; j < temRowStr.size(); j++){
                currentRow += temRowStr[j];
            }
                res.emplace_back(currentRow);
                temRowStr.clear();
        }
            else{
                int spaceCount1 = maxWidth - currentSize;
                for(int k = 0; k < spaceCount1; k++){
                    temRowStr[0] += " ";
                }
                res.emplace_back(temRowStr[0]);
                temRowStr.clear();
        }
        currentSize = 0;        
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        int currentSize = 0;
        string currentStr = "";
        vector<string> temRowStr;
        vector<string> res;
        for(int i = 0; i < n; i++){
            currentSize += words[i].size();
            if(currentSize + temRowStr.size() <= maxWidth)
                temRowStr.emplace_back(words[i]);
            else{
                currentSize -= words[i].size();
                fullJustify2(temRowStr, res, currentSize, maxWidth, false);
                i--;
            }
        }
        if(!temRowStr.empty()){
            fullJustify2(temRowStr, res, currentSize, maxWidth, true);
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    vector<string> tem = sol.fullJustify(words, 16);
    for(int i = 0; i < tem.size(); i++){
        cout << tem[i] << endl;
    }
    return 0;
}