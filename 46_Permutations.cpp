class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<bool> visited(nums.size(), false);
        vector<int> cur;
        permute(nums, ans, 0, cur, visited);
        return ans;
    }
private:
    void permute(vector<int>& nums, vector<vector<int>>& ans, int step, vector<int> cur, vector<bool> visited) {
        if (step >= nums.size()) {
            ans.push_back(cur);
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (!visited[i]) {
                cur.push_back(nums[i]);
                visited[i] = true;
                permute(nums, ans, step + 1, cur, visited); 
                cur.pop_back();
                visited[i] = false; 
            }
        }
    }
};
