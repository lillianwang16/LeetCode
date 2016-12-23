class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        for (size_t i = 0; i < s.length(); ++i) {
            ans = ans *26 + (s[i] - 'A' + 1); 
        }
        return ans;
    }
};
