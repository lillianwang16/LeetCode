class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ans_ele;
        sort(candidates.begin(), candidates.end());
        combinationSum(candidates, ans, ans_ele, target, 0);
        return ans;
    }
private:
    void combinationSum(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& ans_ele, int target, int step) {
        if (step >= candidates.size()) {
            return;
        }
        if (target == 0) {
            ans.push_back(ans_ele);
            return;
        }
        for (size_t i = step; i < candidates.size(); ++i) {
            int temp = target - candidates[i];
            if (temp < 0) {
                break;
            }
            ans_ele.push_back(candidates[i]);
            combinationSum(candidates, ans, ans_ele, temp, i);
            ans_ele.pop_back();
        }
        return;
    }
};
