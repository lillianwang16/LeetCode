/*
//DP with O(n) space and O(n2) time. TLE.
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN;
        vector<int> rec(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j <= i; ++j) {
                if (j == i) {
                    rec[j] = nums[j];
                    res = max(res, nums[j]);
                } else {
                    int temp = nums[i] * rec[j];
                    res = max(res, temp);
                    rec[j] = temp;
                }
            }
        }
        return res;
    }
};
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int pos = 0;
        int neg = 0;
        int res = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            int temp1 = pos * nums[i];
            int temp2 = neg * nums[i];
            if (nums[i] > 0) {
                 pos = max(nums[i], temp1);
                 neg = temp2;
            } else {
                pos = temp2;
                neg = min(nums[i], temp1);
            } 
            res = max(res, pos);
        }
        return res;
    }
};