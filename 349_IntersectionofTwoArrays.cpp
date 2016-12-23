class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, bool> nums_map, ans_map;
        for (int i : nums1) {
            nums_map[i] = true;
        }
        for (int i: nums2) {
            if (nums_map[i] && !ans_map[i]) {
                ans.push_back(i);
                ans_map[i] = true;
            }
        }
        return ans;
    }
};
