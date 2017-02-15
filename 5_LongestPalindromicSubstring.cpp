class Solution {
public:
    string longestPalindrome(string s) {
        int cnt = 0, i = 0, j = 0, p = 0, q = 0;
        while (i < s.length()) {
            while (j + 1 < s.length() && s[j  + 1] == s[i]) {
                ++j;
            }
            int m = i, n = j;
            i = j + 1;
            while (m > 0 && n < s.length() && s[m - 1] == s[n + 1]) {
                --m;
                ++n;
            }
            if (n - m + 1 > cnt) {
                p = m;
                q = n;
                cnt = n - m + 1;
            }
        }
        return (s.substr(p, q - p + 1));
    }
};
