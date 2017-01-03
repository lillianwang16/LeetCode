class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        vector<int> cnt(26);
        for (size_t i = 0; i < s.length(); ++i) {
            ++cnt[s[i] - 'a']; 
            --cnt[t[i] - 'a']; 
        }
        for (int i = 0; i < 26; ++i) {
            if (cnt[i]) {
                return false;
            }
        }
        return true;
    }
};
