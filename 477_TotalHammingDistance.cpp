class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            int test = 1 << i;
            int cnt = 0;
            for (size_t j = 0; j < nums.size(); ++j) {
                if (nums[j] & test) {
                    ++cnt;
                }
            }
            ans += cnt * (nums.size() - cnt);
        }
        return ans;
    }
};
