/*
// Two passes from left and right, save the result needed.
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l = nums.size(); 
        vector<int> res;
        if (l == 0 || k == 0) {
            return res;
        }
        vector<int> left(l);
        vector<int> right(l);
        int lm, rm;
        for (int i = 0; i < l; ++i) {
            if (i % k == 0) {
                lm = INT_MIN;
            }
            lm = max(lm, nums[i]);
            left[i] = lm;
            int j = l - i - 1;
            if (j % k == 0) {
                rm = INT_MIN;
            }
            rm = max(rm, nums[j]);
            right[j] = rm;
        }
        for (int i = 0; i <= l - k; ++i) {
            res.push_back(max(left[i + k - 1], right[i]));
        }
        return res;
    }
};
*/

// Using deque.
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l = nums.size();
        deque<int> dq;
        vector<int> res;
        for (int i = 0; i < l; ++i) {
            if (!dq.empty() && dq.front() < i + 1 - k) {
                dq.pop_front();
            }
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k - 1) {
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};
