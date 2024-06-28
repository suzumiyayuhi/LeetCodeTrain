class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        vector<int> res;
        while(left < right){
            int tem = numbers[left] + numbers[right];
            if(tem > target)
                right--;
            else if(tem < target)
                left++;
            else{
                res.emplace_back(left + 1);
                res.emplace_back(right + 1);
                break;
            }
        }
        return res;
    }
};