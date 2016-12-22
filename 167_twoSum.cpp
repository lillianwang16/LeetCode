/*
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        for (unsigned int i = 0; i < numbers.size(); ++i) {
            if (i < numbers.size() - 2 && numbers[i] == numbers[i + 1] && numbers[i + 1] == numbers[i + 2] ) {continue;}
            for (unsigned int j = i + 1; j < numbers.size(); ++j) {
                if (numbers[i] + numbers[j] == target) {
                    ans.push_back(i + 1);
                    ans.push_back(j + 1);
                    break;
                }
            }
        }
        return ans;
    }
};
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        unsigned int i = 0, j = numbers.size() - 1;
        while (numbers[i] + numbers[j] != target) {
            if (numbers[i] + numbers[j] < target) {
                ++i;
            } else {
                --j;
            }
        }
        ans.push_back(i + 1);
        ans.push_back(j + 1);
        return ans;
    }
};
