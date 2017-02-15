class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> place;
        int cnt = 0, p_cur = -1;
        for (int i = 0; i < s.length(); ++i) {
            if (place.find(s[i]) != place.end()) {
                p_cur = max(p_cur, place[s[i]]);
            }
            place[s[i]] = i;
            cnt = max(cnt, i - p_cur);
        }
        return cnt;
    }
};
