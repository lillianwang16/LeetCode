/*
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        vector<int> ans;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] == target && (mid == 0 || nums[mid - 1] != target)) {
                ans.push_back(mid);
                break;
            }    
            if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        if (ans.empty()) {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] == target && (mid == nums.size() - 1 || nums[mid + 1] != target)) {
                ans.push_back(mid);
                break;
            }    
            if (nums[mid] > target) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        vector<int> ans(2, -1);
        if (nums.empty()) {
            return ans;
        }
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        if (nums[lo] != target) {
            return ans;
        } else {
            ans[0] = lo;
        }
        hi = nums.size() - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2 + 1;
            if (nums[mid] > target) {
                hi = mid - 1;
            } else {
                lo = mid;
            }
        }
        ans[1] = lo;
        return ans;
    }
};
