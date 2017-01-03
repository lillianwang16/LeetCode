class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> cnt;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (cnt[nums[i]]) {
                return true;
            } else {
                cnt[nums[i]] = true;
            }
        }
        return false;
    }
};
