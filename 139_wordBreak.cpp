class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.length() == 0) 
            return true;
        int len = s.length();
        vector<bool> f(len + 1, false);
        f[0] = true;
        for (int i = 1; i <= len; ++i) {
            for (string word : wordDict) {
                int word_len = word.length();
                if (i >= word_len && f[i - word_len] && s.substr(i - word_len, word_len) == word) {
                    f[i] = true;
                    break;
                }
            }
        }
        return f[len];
    }
};

