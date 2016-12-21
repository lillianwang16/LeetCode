/*
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for (unsigned int i = 0; i < nums.size(); ++i) {
            if (i == nums.size() - 1) {
                ans.push_back(nums[i]);
            }else if (nums[i] != nums[i + 1]) {
                ans.push_back(nums[i]);
            }else {
                ++i;
            }
    }
        return ans;
    }
};
*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        diff &= -diff;
        vector<int> ans = {0, 0};
        for (int i : nums) {
            if ((i & diff) == 0) {
                ans[0] ^= i;
            } else {
                ans[1] ^= i;
            }
        }
        return ans;
    }
};
