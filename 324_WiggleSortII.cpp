class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int l = nums.size();
        nth_element(nums.begin(), nums.begin() + l / 2, nums.end());
        int med = nums[l / 2];
        #define A(i) nums[(1 + i * 2) % (l | 1)]
        int lo = 0, hi = l - 1; 
        for (int i = 0; i <= hi; ++i) {
            while (A(i) < med && i < hi) {
                swap(A(i), A(hi));
                --hi;
            }
            while (A(i) > med && i > lo) {
                swap(A(i), A(lo));
                ++lo;
            }
        }
    }
};