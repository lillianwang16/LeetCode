/*
//If we step on 0, we cannot move forward;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool flag = true;
        for (int i = 0; i < nums.size(); ++i) {
            if (!flag) {
                break;
            }
            if (nums[i] == 0 && i != nums.size() - 1) {
                flag = false;
                int j = i - 1;
                while (j >= 0) {
                    if (nums[j] > (i - j)) {
                        flag = true;
                        break;
                    }
                    --j;
                }
            }
        }
        return flag;
    }
};
*/
//Find the max index we can get.
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), i = 0, reach = 0;
        for (; i < n && i <= reach; ++i) {
            reach = max(reach, i + nums[i]);
        }
        return n == i;
    }
};
