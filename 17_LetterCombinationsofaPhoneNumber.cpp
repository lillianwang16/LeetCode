class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int p = 0;
        for (int i = 0; i < 8; ++i) {
            string num_letter;
            int cnt = (i == 5 || i == 7 ? 4 : 3);
            for (int j = 0; j < cnt; ++j) {
                num_letter += (char)'a'+ p;
                ++p;
            }
            letters_.push_back(num_letter);
        }
        vector<string> ans;
        string str;
        letterCombinations(digits, 0, str, ans);
        return ans;
    }
private:
    vector<string> letters_; 
    void letterCombinations(string digits, int step, string cur, vector<string>& ans) {
        if (step == digits.length() && step != 0) {
            ans.push_back(cur);
            return;
        }
        int p = digits[step] - '2';
        for (int i = 0; i < letters_[p].length(); ++i) {
            letterCombinations(digits, step + 1, cur + letters_[p][i], ans);
        }
    }
};

