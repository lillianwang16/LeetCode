/*
class Solution {
public:
    int firstUniqChar(string s) {
        int ans = -1;
        unordered_map<char, int> char_map;
        for (char c : s) {
            ++char_map[c];
        }
        for (size_t i = 0; i < s.length(); ++i) {
            if (char_map[s[i]] == 1) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};
*/
class Solution {
public:
    int firstUniqChar(string s) {
        int ans = -1;
        vector<int> char_map(26);
        for (char c : s) {
            ++char_map[c - 'a'];
        }
        for (size_t i = 0; i < s.length(); ++i) {
            if (char_map[s[i] - 'a'] == 1) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};
