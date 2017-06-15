class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, vector<string>> m;
        m[""] = {""};
        return wordBreakHelper(s, wordDict, m);
    }
private:
    vector<string> wordBreakHelper(string s, vector<string>& wordDict, unordered_map<string, vector<string>>& m) {
        if (m.find(s) != m.end()) {
            return m[s];
        }
        vector<string> res;
        for (string word : wordDict) {
            if (!s.compare(0, word.size(), word)) {
                vector<string> sub_string = wordBreakHelper(s.substr(word.length()), wordDict, m);
                for (string sub : sub_string) {
                    res.push_back(word + ((sub.length() == 0) ? "" : " ") + sub);
                }
            }
        }
        m[s] = res;
        return res;
    }
};