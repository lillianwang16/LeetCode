class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string str;
        restore(res, s, 0, 0);
        return res;
    }
private:
    void restore(vector<string>& res, string s, int cnt, int p) {
        if (cnt == 3) {
            if (atoi(s.substr(p).c_str()) <= 255 && !(s.length() - p > 1 && s[p] == '0')) {
                res.push_back(s);
            } 
            return;
        }
        if (s.length() - p > (4 - cnt) * 3) {
            return;
        }
        for (int i = 1; i <= 3; ++i) {
            if (p + i < s.length() && atoi(s.substr(p, i).c_str()) <= 255 && !(i != 1 && s[p] == '0')) {
                s.insert(p + i, ".");
                restore(res, s, cnt + 1, p + i + 1);
                s.erase(p + i, 1);
            } 
        }
    }
};