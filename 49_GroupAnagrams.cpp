class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> m;
        vector<vector<string>> ans;
        int cnt = 0;
        for (string str : strs) {
            vector<char> cur;
            for (int i = 0; i < str.length(); ++i) {
                cur.push_back(str[i]);
            }
            sort(cur.begin(), cur.end());
            string strr;
            for (int i = 0; i < str.length(); ++i) {
                strr += cur[i];
            }
            if (m.find(strr) == m.end()) {
                m[strr] = cnt;
                vector<string> n(1, str);
                ans.push_back(n);
                ++cnt;
            } else {
                ans[m[strr]].push_back(str);
            }
        }
        return ans;
    }
};
// This can be optimized by using prime numbers. 
