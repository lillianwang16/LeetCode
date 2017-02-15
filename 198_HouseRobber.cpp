/*
class Solution {
public:
    int rob(vector<int>& nums) {
        const int len = nums.size();
        if (len < 3) {
            int ans = 0;
            for (int i = 0; i < len; ++i) {
                ans = max(ans, nums[i]);
            }
            return ans;
        }
        vector<int> f(len);
        f[0] = nums[0];
        f[1] = nums[1];
        f[2] = f[0] + nums[2];
        for (int i = 3; i < len; ++i) {
            f[i] = max(nums[i] + f[i - 2], nums[i] + f[i - 3]);
        }
        return max(f[len - 1], f[len - 2]);
        
    }
};

*/
//using o(1) space
/*
class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        vector<int> f(3);
        for (int i = 0; i < len; ++i) {
            f[i % 3] = max(nums[i] + f[i % 3], nums[i] + f[(i % 3 + 1) % 3]);
        }
        return max(f[0], max(f[1], f[2]));
        
    }
};
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int preNo = 0, preYes = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int temp = preNo;
            preNo = max(preNo, preYes);
            preYes = temp + nums[i];
        }
        return max(preNo, preYes);
    }
};

