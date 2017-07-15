class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int index = i, cnt = 0;
            while (nums[index] != -1) {
                int temp = nums[index];
                nums[index] = -1;
                index = temp;
                ++cnt;
            }
            res = max(res, cnt);
        }
        return res;
    }
};