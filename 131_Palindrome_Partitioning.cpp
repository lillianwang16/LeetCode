class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> cur;
        partitionHelper(s, ans, cur, 0);
        return ans;
    }
private:
    void partitionHelper(string s, vector<vector<string>>& ans, vector<string>& cur, int p) {
        if (p == s.length()) {
            ans.push_back(cur);
            return;
        }
        for (int i = 1; p + i <= s.length(); ++i) {
            string temp = s.substr(p, i);
            if (check(temp)) {
                cur.push_back(temp);
                partitionHelper(s, ans, cur, p + i);
                cur.pop_back();
            }
        }
    }
    bool check(string s) {
        int front = 0, end = s.length() - 1;
        while (front <= end) {
            if (s[front] != s[end]) {
                return false;
            }
            ++front;
            --end;
        }
        return true;
    }
};