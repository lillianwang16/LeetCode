class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        while (hi > lo + 1) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] > nums[lo] && nums[mid] > nums[hi]) {
                lo = mid;
            } else if (nums[mid] < nums[lo] && nums[mid] < nums[hi]) {
                hi = mid;
            } else {
                return min(nums[lo], nums[hi]);
            }
        }
        return min(nums[lo], nums[hi]);
    }
};
