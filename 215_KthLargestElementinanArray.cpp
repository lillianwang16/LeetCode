class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int lo = 0, hi = nums.size() - 1;
        while (lo <= hi) {
            int first = lo, end = hi;
            int key = nums[first];
            while (first < end) {
                while (first < end && nums[end] <= key) {
                    --end;
                }
                nums[first] = nums[end];
                while (first < end && nums[first] >= key) {
                    ++first;
                }
                nums[end] = nums[first];
            }
            nums[first] = key;
            if (first == k - 1) {
                return key;
            } else if (k - 1 < first) {
                hi = first - 1;
            } else {
                lo = first + 1;
            }
        }
    }
};