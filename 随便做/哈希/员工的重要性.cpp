/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int n= employees.size();
        vector<Employee*> vec(2001, NULL);
        for(int i = 0; i < n; i++)
            vec[employees[i]->id] = employees[i];

        int res = 0;
        queue<int> qid;
        qid.push(id);
        while(!qid.empty())
        {
            int &ee = qid.front();
            res += vec[ee]->importance;
            for(int j = 0; j < vec[ee]->subordinates.size(); j++)
                qid.push(vec[ee]->subordinates[j]);
            qid.pop();
        }

        return res;
    }
};