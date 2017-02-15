ass Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int lo = 1, hi = nums.size() - 1;
        while (lo <= hi) {
            int cnt = 0, mid = (lo + hi) / 2;
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] <= mid)     ++cnt;
            }
            if (cnt > mid) {
                hi = mid - 1; 
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};
*/
// o(n) two pointers
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[nums[0]];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        fast = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
    
