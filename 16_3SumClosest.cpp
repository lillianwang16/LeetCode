class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int d = INT_MAX;
        int res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            int target2 = target - nums[i];
            int front = i + 1;
            int end = nums.size() - 1;
            while (front < end) {
                int temp = nums[front] + nums[end];
                if (d > abs(temp + nums[i] - target)) {
                    d = abs(temp + nums[i] - target);
                    res = temp + nums[i];
                }
                if (temp == target2) {
                    return target;
                }
                if (temp < target2) {
                    ++front;
                }
                if (temp > target2) {
                    --end;
                }
            }
        }
        return res;
    }
};