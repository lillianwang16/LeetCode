class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        vector<char> par = {'(', ')'};
        remove(s, res, 0, 0, par);
        return res;
    }
private:
    void remove(string& s, vector<string>& res, int last_i, int last_j, vector<char> par) {
        for (int st = 0, i = last_i; i < s.length(); ++i) {
            if (s[i] == par[0]) {
                ++st;
            }
            if (s[i] == par[1]) {
                --st;
            }
            if (st >= 0) continue;
            for (int j = last_j; j <= i; ++j) {
                if (s[j] == par[1] && (j == last_j || s[j - 1] != par[1])) {
                    string temp = s.substr(0, j) + s.substr(j + 1, s.length());
                    remove(temp, res, i, j, par);
                }
            }
            return;
        }
        reverse(s.begin(), s.end());
        if (par[0] != ')') {
            par[0] = ')';
            par[1] = '(';
            remove(s, res, 0, 0, par);
        } else {
            res.push_back(s);
        }
    }
};