class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        vector<vector<int>> res;
        subsets(res, cur, nums, 0);
        return res;
    }
private:
    void subsets(vector<vector<int>>& res, vector<int> cur, vector<int>& nums, int step) {
        if (step == nums.size()) {
            res.push_back(cur);
            return;
        }
        //cur.push_back(nums[step]);
        subsets(res, cur, nums, step + 1);
        //cur.pop_back();
        cur.push_back(nums[step]);
        subsets(res, cur, nums, step + 1);
    }
};