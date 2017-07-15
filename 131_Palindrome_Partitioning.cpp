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

/*
//Memorized backtracking. Worse result. 
class Solution {
public:
    vector<vector<string>> partition(string s) {
        unordered_map<string, vector<vector<string>>> m;
        return partitionHelper(s, m);
    }
private:
    vector<vector<string>> partitionHelper(string s, unordered_map<string, vector<vector<string>>>& m) {
        if (m.find(s) != m.end()) {
            return m[s];
        }
        vector<vector<string>> ans;
        if (s.length() == 0) {
            return ans;
        }
        for (int i = 1; i <= s.length(); ++i) {
            string str = s.substr(0, i);
            if (check(str)) {
                vector<vector<string>> subs = partitionHelper(s.substr(i), m);
                if (subs.size() > 0) {
                    for (vector<string> sub : subs) {
                        sub.insert(sub.begin(), str);
                        ans.push_back(sub);
                    }
                } else {
                    vector<string> sub;
                    sub.push_back(str);
                    ans.push_back(sub);
                }
            }
        }
        m[s] = ans;
        return ans;
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
*/