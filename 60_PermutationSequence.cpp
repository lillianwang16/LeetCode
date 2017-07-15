class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> s;
        int cnt = 1;
        for (int i = 1; i <= n; ++i) {
            s.push_back(i);
            cnt *= i;
        }
        --k;
        string res;
        for (int i = 0; i < n; ++i) {
            cnt /= (n - i);
            int p = k / cnt;
            res += to_string(s[p]);
            s.erase(s.begin() + p);
            k %= cnt; 
        }
        return res;
    }
};