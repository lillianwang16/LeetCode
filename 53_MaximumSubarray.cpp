class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int ans = nums[0], min_sum = 0, count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            count += nums[i];
            ans = max(count - min_sum, ans);
            min_sum = min(count, min_sum);
        }
        return ans;
    }
};
