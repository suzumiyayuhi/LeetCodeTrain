#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class RandomizedSet {
public:
    vector<int> valSet;
    unordered_map<int, int> hashhh;

    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(hashhh.find(val) != nullptr)
            return false;
        hashhh.insert(make_pair(val, valSet.size()));
        valSet.emplace_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(hashhh.find(val) == nullptr)
            return false;
        int indx = hashhh[val];
        valSet[indx] = valSet.back();
        valSet.pop_back();
        hashhh.erase(val);
        return true;
    }
    
    int getRandom() {
        return valSet[rand() % valSet.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */