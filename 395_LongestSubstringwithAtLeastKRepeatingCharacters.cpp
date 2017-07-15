class Solution {
public:
    int longestSubstring(string s, int k) {
        return helper(s, 0, s.length() - 1, k);
    }
private:
    int helper(string s, int lo, int hi, int k) {
        if (hi - lo + 1 < k) return 0;
        vector<int> nums(26);
        for (int i = lo; i <= hi; ++i) {
            ++nums[s[i] - 'a'];
        }
        vector<int> p;
        p.push_back(lo);
        for (int i = 0; i < 26; ++i) {
            if (nums[i] > 0 && nums[i] < k) {
                for (int j = lo; j <= hi; ++j) {
                    if (s[j] == i + 'a') {
                        p.push_back(j);
                    }
                }
            }
        }
        p.push_back(hi);
        int n = p.size();
        if (n == 2) {
            return hi - lo + 1;
        }
        int res = 0;
        for (int i = 0; i <= n - 2; ++i) {
            int l = (i == 0) ? p[i] : p[i] + 1;
            int h = (i == n - 2) ? p[i + 1] : p[i + 1] - 1;
            res = max(helper(s, l, h, k), res);
        }
        return res;
    }
};