/*
// DFS. TLE.
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int res = 0, sum = 0;
        combination(res, sum, nums, target);
        return res;
    }
private:
    void combination(int& res, int sum, vector<int>& nums, int target) {
        if (sum > target) {
            return;
        }
        if (sum == target) {
            ++res;
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            combination(res, sum, nums, target);
            sum -= nums[i];
        }
    }
};
*/
// DP.
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1);
        dp[0] = 1;
        for (int i = 1; i <= target; ++i) {
            int sum = 0;
            for (int j = 0; j < nums.size(); ++j) {
                int t = i - nums[j];
                if (t >= 0) {
                    sum += dp[t];
                }
            }
            dp[i] = sum;
        }
        return dp[target];
    }
};