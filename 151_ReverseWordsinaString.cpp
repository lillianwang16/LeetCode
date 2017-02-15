/*
//erase ' ' when meet them
class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        int p = 0;
        while (s.length() > 0 && p < s.length()) {
            char c = s[p];
            if (s[p] == ' ') {
                s.erase(p, 1);
                continue;
            }
            if (p < s.length()) {
                if (p != 0)
                    s.insert(s.begin() + p++, ' ');
                int word_p = p;
                while (word_p < s.length() && s[word_p] != ' ')
                    ++word_p;
                reverse(s.begin() + p, s.begin() + word_p);
                p = word_p;
            }
        }
    }
};
*/

// ignore ' ' and copy word
class Solution {
public:
    void reverseWords(string &s) {
        int p_cur = 0, p_word_start = 0, p_word_end = 0;
        while (p_cur < s.length()) {
            while (p_cur < s.length() && s[p_cur] == ' ') 
                ++p_cur;
            if (p_cur < s.length()) {
                if (p_word_end)
                    s[p_word_end++] = ' ';
                p_word_start = p_word_end;
                while (p_cur < s.length() && s[p_cur] != ' ') {
                    s[p_word_end++] = s[p_cur++];
                }
                reverse(s.begin() + p_word_start, s.begin() + p_word_end);
            }
        }
        s.resize(p_word_end);
        reverse(s.begin(), s.end());
    }
};


