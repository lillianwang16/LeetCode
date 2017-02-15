/*
// Backtracking. Find the ans with all 1s at first and then revise it.
class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> ans;
        generateOnes(word, ans, 0);
        return ans;
    }
private:
    void generateOnes(string& cur, vector<string>& ans, int p) {
        if (p == cur.length()) {
            int cnt_one = 0, st = 0, en = 0;
            string word = cur;
            while (en < word.length()) {
                if (word[en] == '1') {
                    st = en;
                    while (en < word.length() && word[en] == '1') {
                        ++en;
                    }
                    int diff = en - st;
                    word.erase(st, diff);
                    en = st;
                    word.insert(st, to_string(diff));
                    while (diff > 0) {
                        ++en;
                        diff /= 10;
                    }
                }
                ++en;
            }
            ans.push_back(word);
            return;
        }
        generateOnes(cur, ans, p + 1);
        char c = cur[p];
        cur[p] = '1';
        generateOnes(cur, ans, p + 1);
        cur[p] = c;
    }
};
*/

/*
// Backtracking. Construct the ans element every time.
class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> ans;
        string cur;
        backTracking(word, cur, ans, 0, 0);
        return ans;
    }
private:
    void backTracking(string& word, string cur, vector<string>& ans, int p, int cnt) {
        if (p == word.length()) {
            if (cnt != 0) {
                cur += to_string(cnt);
            }
            ans.push_back(cur);
            return;
        }
        backTracking(word, cur, ans, p + 1, cnt + 1);
        if (cnt != 0) 
            cur += to_string(cnt);
        cur += word[p];
        backTracking(word, cur, ans, p + 1, 0);
    }
};
*/

// Bit manipulation.
class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> ans;
        for (int i = 0; i < (1 << word.length()); ++i) {
            ans.push_back(generateAbbreviation(word, i));
        }
        return ans;
    }
    string generateAbbreviation(const string& word, int num) {
        string str;
        int cnt = 0, x = 1;
        for (int i = 0; i < word.size(); ++i, x <<= 1) {
            if ((num & x) == 0) {
                if (cnt != 0) {
                    str += to_string(cnt);
                    cnt = 0;
                }
                str += word[i];
            } else {
                ++cnt;
            }
        }
        if (cnt != 0) {
            str += to_string(cnt);
        }
        return str;
    }
};
