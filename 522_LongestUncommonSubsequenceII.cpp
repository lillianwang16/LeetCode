class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(), cmp);
        for (int i = strs.size() - 1; i >= 0; --i) {
            if (isLUS(i, strs)) {
                return (int)strs[i].length();
            }
        }
        return -1;
    }
private:
    bool isLUS(int p, vector<string>& strs) {
        string str = strs[p];
        for (int i = strs.size() - 1; i >= 0; --i) {
            if (i == p) continue;
            if (strs[i].length() < str.length())    return true;
            int j = 0, k = 0;
            while (j < str.length() && k < strs[i].length()) {
                if (str[j] == strs[i][k++]) {
                    ++j;
                }
            }
            if (j == str.length())  return false;
        }
        return true;
    }
    static bool cmp(string a, string b) {
        return a.length() < b.length();
    }
};