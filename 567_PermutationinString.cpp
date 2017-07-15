class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length(), len2 = s2.length();
        vector<int> s(26, 0);
        for (int i = 0; i < len1; ++i) {
            ++s[s1[i] - 'a'];
            --s[s2[i] - 'a'];
        }
        if (allZero(s)) return true;
        for (int i = len1; i < len2; ++i) {
            --s[s2[i] - 'a'];
            ++s[s2[i - len1] - 'a'];
            if (allZero(s)) return true;
        }
        return false;
    }
private:
    bool allZero(vector<int> s) {
        for (int j = 0; j < 26; ++j) {
            if (s[j] != 0)
                return false;
        }
        return true;
    }
};