class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if (nums.size() < 3)
            return 0;
        sort(nums.begin(), nums.end());
        int cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int lo = i + 1, hi = nums.size() - 1;
            while (lo < hi) {
                while (lo < hi && nums[i] + nums[lo] + nums[hi] >= target) {
                    --hi;
                }
                cnt += hi - lo;
                ++lo; 
            }
        }
        return cnt;
    }
};
