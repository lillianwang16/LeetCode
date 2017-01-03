class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum_n = (nums.size() + 1) * nums.size() / 2;
        int sum_nums = accumulate(nums.begin(), nums.end(), 0);
        return sum_n - sum_nums; 
    }
};
