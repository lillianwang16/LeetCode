class Solution {

/*
public:
    char findTheDifference(string s, string t) {
        vector<int> nums_s = find(s);
        vector<int> nums_t = find(t);
        char ans;
        for (int i = 0; i < 26; ++i) {
            if (nums_s[i] - nums_t[i]) {
                ans = i + 'a';
                break;
            }
        }
        return ans;
    }
private:
    vector<int> find(const string& s) {
        vector<int> nums(26);
        for (unsigned int i = 0; i < s.length(); ++i) {
            char temp = s[i];
            ++nums[temp - 'a'];
        }
        return nums;
    }
};
*/

public:
    char findTheDifference(string s, string t) {
        char r = 0;
        for (char c : s) {
            r ^= c;
        }
        for (char c : t) {
            r ^= c;
        }
        return r;
    }
};
