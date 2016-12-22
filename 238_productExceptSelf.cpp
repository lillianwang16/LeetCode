ass Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        ans[0] = 1;
        for (unsigned int i = 1; i < nums.size(); ++i) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        int right = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            ans[i] *= right;
            right *= nums[i];
        }
        return ans;
    }
};
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        int from_first = 1, from_last = 1;
        for (unsigned int i = 0; i < nums.size(); ++i) {
            ans[i] *= from_first;
            from_first *= nums[i];
            ans[nums.size() - 1 - i] *= from_last;
            from_last *= nums[nums.size() - 1 - i];
        }
        return ans;
    }
};
