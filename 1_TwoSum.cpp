class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> nums_map;
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums_map.find(target - nums[i]) != nums_map.end()) {
                ans.push_back(nums_map[target - nums[i]]);
                ans.push_back(i);
                return ans;
            }
            nums_map[nums[i]] = i;
        }
        return ans;
    }
};
