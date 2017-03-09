class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> m (128, 0);
        for (char c : t) {
            ++m[c];
        }
        int st = 0, en = 0, min_len = INT_MAX, min_st = 0, cnt = t.length();
        while (en < s.size()) {
            if (m[s[en]] > 0) {
                --cnt;
            }
            --m[s[en]];
            ++en;
            while (cnt == 0) {
                if (en - st < min_len) {
                    min_st = st;
                    min_len = en - st;
                }
                ++m[s[st]];
                if (m[s[st]] > 0) {
                    ++cnt;
                }
                ++st;
            }
        }
        return min_len == INT_MAX ? "" : s.substr(min_st, min_len);
    }
};
