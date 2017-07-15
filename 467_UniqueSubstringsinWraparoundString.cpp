//DP.
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int res = 0;
        int cnt = 1;
        vector<int> m(26);
        if (p.length() == 0)    return 0;
        m[p[0] - 'a'] = 1;
        for (int i = 1; i < p.length(); ++i) {
            if (p[i] - 'a' == (p[i - 1] - 'a' + 1) % 26) {
                ++cnt;
            } else {
                cnt = 1;
            }  
            int v = p[i] - 'a';
            m[v] = max(m[v], cnt);
        }
        for (int i = 0; i < 26; ++i) {
            res += m[i];
        }
        return res;
    }
};