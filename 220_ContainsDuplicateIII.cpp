/*
// O(n2). TLE.
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.size() == 0) {
            return false;
        }
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j - i <= k && j < nums.size(); ++j) {
                if (labs((long long)nums[i] - (long long)nums[j]) <= t) {
                    return true;
                }
            }
        }
        return false;
    }
};
*/

// Using set as a window. 
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> window;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > k) {
                window.erase(nums[i - k - 1]);
            }
            long long cur = nums[i];
            set<long long> :: iterator it = window.lower_bound(cur - t);
            if (it != window.end() && *it - cur <= t) {
                return true;
            }
            window.insert(cur);
        }
        return false;
    }
};
