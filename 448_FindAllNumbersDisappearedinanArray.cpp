class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        size_t i = 0;
        vector<int> ans;
        while (i < nums.size()) {
            while (nums[nums[i] - 1] != nums[i]) {
                int temp = nums[nums[i] - 1];
                nums[nums[i] - 1] = nums[i];
                nums[i] = temp;
            }
            ++i;
        }
        for (size_t j = 0; j < nums.size(); ++j) {
            if (nums[j] != j + 1) {
                ans.push_back(j + 1);
            }
        }
        return ans;
    }
};
