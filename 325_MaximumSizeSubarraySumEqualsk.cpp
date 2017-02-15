//save the sum of the first n numbers
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        map<int, int> nums_sum;
        int sum = 0, ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (sum == k)  
                ans = max(ans, i + 1);
            else if (nums_sum.find(sum - k) != nums_sum.end()) 
                ans = max(ans, i - nums_sum[sum - k]);
            if (nums_sum.find(sum) == nums_sum.end()) 
                nums_sum[sum] = i;
        }
        return ans;
    }
};
