class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> cur;
        vector<vector<int>> res;
        combine(res, cur, 1, n, k);
        return res;
    }
private:
    void combine(vector<vector<int>>& res, vector<int>& cur, int step, int n, int k) {
        if (step > n) return;
        cur.push_back(step);
        if (cur.size() == k) {
            res.push_back(cur);
        } else {
            combine(res, cur, step + 1, n, k);
        }
        cur.pop_back();
        combine(res, cur, step + 1, n, k);
    }
};