class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            int s = 0, e = i - 1;
            int sum = 0;
            while (s <= e) {
                if (s == e) {
                    sum +=  dp[s] * dp[e];
                } else {
                    sum += 2 * dp[s] * dp[e];
                }
                ++s;
                --e;
            }
            dp[i] = sum;
        }
        return dp[n];
    }
};