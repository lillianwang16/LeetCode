/*
class Solution {
public:
    int lengthLongestPath(string input) {
        int p = 0, cnt = 0;
        lengthLongestPath(input, p, cnt, 0, false);
        return ans;
    }
private:
    void lengthLongestPath(string& s, int& p, int cnt, int step, bool flag) {
        if (p >= s.length()) {
             if (flag) {
                 ans = max(ans, cnt + step - 1);
            }
            return;
        }
        int cnt_cur = 0, p_cur = p, cur_step = 0;
        while (s[p_cur] == '\t') {
            ++cur_step;
            ++p_cur;
        }
        if (cur_step < step) {
            if (flag) {
                 ans = max(ans, cnt + step - 1);
            }
            return;
        }
        while (p_cur < s.length() && s[p_cur] != '\n') {
            if (s[p_cur] == '.') {
                flag = true;
            }
            ++cnt_cur;
            ++p_cur;
        }
        p = p_cur + 1;
        cnt += cnt_cur;
        lengthLongestPath(s, p, cnt, step + 1, flag);
        cnt -= cnt_cur;
        lengthLongestPath(s, p, cnt, step, false);
    }
    int ans = 0;
};
*/
//Solution using vector for record.
class Solution {
public:
    int lengthLongestPath(string input) {
        int ans = 0, p = 0;
        vector<int> level(200);
        level[0] = 0;
        while (p < input.size()) {
            int l = 1, cnt = 0;
            bool isFile = false;
            while (input[p] == '\t') {
                ++l;
                ++p;
            }
            while (p < input.size() && input[p] != '\n') {
                if (input[p] == '.') {
                    isFile = true;
                }
                ++cnt;
                ++p;
            }
            level[l] = level[l - 1] + cnt + 1;
            if (isFile) {
                ans = max(ans, level[l] - 1);
            }
            ++p;
        }
        return ans;
    }
};

