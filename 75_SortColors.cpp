class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero_index = 0, two_index = nums.size() - 1;
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] == 2 && two_index > i) {
                swap(nums[i], nums[two_index--]);
            }
            while (nums[i] == 0 && zero_index < i) {
                swap(nums[i], nums[zero_index++]);
            }
        }
    }
};


