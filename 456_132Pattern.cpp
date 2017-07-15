/*
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3)    return false;
        vector<int> n(nums.size());
        n[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] <= n[i - 1]) {
                n[i] = nums[i];
            } else {
                for (int j = i - 1; j >= 0; --j) {
                    if (nums[i] < nums[j] && nums[i] > n[j]) {
                        return true;
                    }
                    n[i] = n[i - 1];
                }
            }
        }
        return false;
    }
};
*/
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3)    return false;
        stack<int> st;
        int s3 = INT_MIN;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] < s3) {
                return true;
            }
            while (!st.empty() && nums[i] > st.top()) {
                //s3 = max(s3, st.top());
                s3 = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};