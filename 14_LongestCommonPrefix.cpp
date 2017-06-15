class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }
        string ans = strs[0];
        for (string str : strs) {
            for (int i = 0; i < ans.length(); ++i) {
                if (i >= str.length() || str[i] != ans[i]) {
                    ans = ans.substr(0, i);
                    break;
                }
                if (ans == "") {
                    return ans;
                }
            }
        }
        return ans;
    }
};