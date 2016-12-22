class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum_nums = 0, min = INT_MAX;
        for (unsigned int i = 0; i < nums.size(); ++i) {
            sum_nums += nums[i];
            if (nums[i] < min) {
                min = nums[i];
            }
        }
        return sum_nums - nums.size() * min;
    }
};
