/*
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = (int)nums.size() - 1;
        while (lo < hi) {
            if (nums[lo] < nums[hi]) {
                return binarySearch(nums, target, lo, hi);
            }
            int mid = lo + (hi - lo) / 2;
            if (target == nums[mid]) {
                return mid;
            }
            if (nums[mid] > nums[lo]) {
                if (target == nums[lo]) {
                    return lo;
                } else if (target < nums[lo] || target > nums[mid]) {
                    lo = mid + 1;
                } else if (target > nums[lo] && target < nums[mid]) {
                    hi = mid;
                }
            } else {
                if (target == nums[hi]) {
                    return hi;
                } else if (target > nums[hi] || target < nums[mid]) {
                    hi = mid;
                } else if (target < nums[hi] && target > nums[mid]){
                    lo = mid + 1;
                }
            }
        }
        if (nums[lo] == target) {
            return lo;
        } else {
            return -1;
        }
    }
private:
    //Recursive binary search.
    int binarySearch(vector<int>& nums, int target, int lo, int hi) {
        if (lo >= hi) {
            if (nums[lo] == target) {
                return lo;
            } else {
                return -1;
            }
        }
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] > target) {
            return binarySearch(nums, target, lo, mid - 1);
        } else if ( nums[mid] < target) {
            return binarySearch(nums, target, mid + 1, hi);
        } else {
            return mid;
        }
    }
    //Iterative binary search.
    int binarySearch(vector<int>& nums, int target, int lo, int hi) {
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] > target) {
                hi = mid - 1;
            } else if ( nums[mid] < target) {
                lo = mid + 1;
            } else {
                lo = mid;
                break;
            }
        }
        if (nums[lo] == target) {
            return lo;
        } else {
            return -1;
        }
    }
};
*/


//Revised binary search.
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo =0, hi = nums.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (target == nums[mid]) {
                return mid;
            }
            if (nums[mid] >= nums[lo]) {
                if (target >= nums[lo] && target < nums[mid]) {
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            } else {
                if (target > nums[mid] && target <= nums[hi]) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
        }
        return (target == nums[lo]) ? lo : -1;
    }
};

//Move mid to real_mid.
/*
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = (int)nums.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] > nums[hi]) {
                lo = mid + 1;
            } else {
                hi =  mid;
            }
        }
        int pivot = lo;
        lo = 0;
        hi = (int)nums.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int real_mid = (mid + pivot) % nums.size();
            if (nums[real_mid] == target) {
                return real_mid;
            } else if (nums[real_mid] > target) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return -1;
    }
};
*/
