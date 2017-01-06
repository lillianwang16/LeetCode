class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = (int)words.size(), ans = 0;
        vector<int> cnt;
        for (string str : words) {
            int temp = 0;
            for (char c : str) {
                temp |= 1 << (c - 'a');
            }
            cnt.push_back(temp);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (!(cnt[i] & cnt[j])) {
                    int temp = words[i].length() * words[j].length();
                    ans = max(ans, temp);
                }
            }
        }
        return ans;
    }
};
