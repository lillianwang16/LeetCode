/*
//DP solution. O(n2).
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int l = nums.size();
        if (l == 0) return 0;
        vector<int> dp(l, 1);
        for (int i = 1; i < l; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        int res = 1;
        for (int i : dp) {
            res = max(res, i);
        }
        return res;
    }
};
*/
//Save the least number of a increasing sequence of length i.
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int l = nums.size();
        vector<int> tails(l);
        int size = 0;
        for (int num : nums) {
            int lo = 0, hi = size;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (tails[mid] < num) {
                    lo = mid + 1;
                } else {
                    hi = mid;
                }
            }
            if (hi == size) ++size;
            tails[hi] = num;
        }
        return size;
    }
};