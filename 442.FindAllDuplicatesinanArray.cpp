/*
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        for (unsigned int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};
*/

/*
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        unsigned int i = 0;
        while (i < nums.size()) {
            if (nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            } else {
                ++i;
            }
        }
        for (unsigned int i = 0; i < nums.size(); ++i) {
            if (i != nums[i] - 1) {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for (unsigned int i = 0; i < nums.size(); ++i) {
            int index = abs(nums[i]) - 1;
            if (nums[index] < 0) {
                ans.push_back(abs(nums[i]));
            }
            nums[index] = -nums[index];
        }
        return ans;
    }
};
