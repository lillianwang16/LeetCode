class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int i = 0, j = 0, sum = 0, len = nums.size();
        while (j < nums.size()) {
            sum += nums[j];
            j++;
            if (sum >= s) {
                len = min(len, j - i);
            }
            while (sum - nums[i] >= s) {
                sum -= nums[i];
                ++i;
                len = min(len, j - i);
            }
        }
        return sum < s ? 0 : len;
    }
};