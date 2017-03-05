class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0) 
            return 0;
        vector<int> dp(s.size() + 1);
        dp[0] = s[0] == '0' ? 0 : 1;
        dp[1] = dp[0];
        for (int i = 1; i < s.size(); ++i) {
            int num = atoi(s.substr(i - 1, 2).c_str());
            if (s[i] == '0') {
                if (num == 0 || num > 26) {
                    return 0;
                } else {
                    dp[i + 1] = dp[i - 1];
                }
            } else {
                if (num > 26 || num < 10) {
                    dp[i + 1] = dp[i];
                } else {
                    dp[i + 1] = dp[i] + dp[i - 1];
                }
            }
        }
        return dp[s.size()];
    }
};
