class Solution {
public:
    string decodeString(string s) {
        string str;
        int i = 0, cnt = 0;
        while (i < s.length()) {
            if (s[i] >= '0' && s[i] <= '9' ) {
                cnt = cnt * 10 + (s[i] -'0'); 
                ++i;
            }
            if (s[i] >= 'a' && s[i] <= 'z') {
                str += s[i];
                ++i;
            }
            if (s[i] == '[') {
                ++i;
                string str_temp, str_new;
                int cnt_left = 1, cnt_right = 0;
                while (cnt_right < cnt_left) {
                    if (s[i] == '[') {
                        ++cnt_left;
                    } 
                    if (s[i] == ']') {
                        ++cnt_right;
                    }
                    if (cnt_right < cnt_left)    str_temp += s[i];
                    ++i;
                }
                str_new = decodeString(str_temp);
                for (int j = 0; j < (cnt > 0 ? cnt : 1); ++j) {
                   str += str_new;
                }
                cnt = 0;
            }
        }
        return str;
    }
};
