class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int i = 0;
        while (i < nums.size()) {
            int j = i + 1, k = nums.size() - 1;
            int target = -nums[i];
            while (k > j) {
                int sum_two = nums[j] + nums[k];
                if (sum_two == target) {
                    vector<int> ans_ele(3, 0);
                    ans_ele[0] = nums[i];
                    ans_ele[1] = nums[j];
                    ans_ele[2] = nums[k];
                    ans.push_back(ans_ele);
                    while (k > j && nums[j + 1] == nums[j]) {
                        ++j;
                    }
                    ++j;
                    while (k > j && nums[k - 1] == nums[k]) {
                        --k;
                    }
                    --k;
                } else if (sum_two > target) {
                    --k;
                } else {
                    ++j;
                }
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) {
                ++i;
            }
            ++i;
        }
        return ans;
    }
};
