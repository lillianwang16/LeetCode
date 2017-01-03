class Solution {
public:
    int longestPalindrome(string s) {
        vector<bool> cnt(60);
        int ans = 0;
        for (size_t i = 0; i < s.length(); ++i) {
            int temp = s[i] - 'A';
            if (cnt[temp]) {
                cnt[temp] = false;
                ans += 2;
            }else {
                cnt[temp] = true;
            }
        }
        for (int i = 0; i < 60; ++i) {
            if (cnt[i]) {
                return ++ans;
            }
        }
        return ans;
        /*
        unordered_set<char> cnt;
        int ans = 0;
        for (size_t i = 0; i < s.length(); ++i) {
            if (cnt.find(s[i]) != cnt.end()) {
                ans += 2;
                cnt.erase(s[i]);
            } else {
                cnt.insert(s[i]);
            }
        }
        if (!cnt.empty()) {
            return ++ans; 
        }else {
            return ans;
        }
        */
    }
};
