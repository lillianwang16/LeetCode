class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int res = 0, sum = 0;
        m[0] = 1;
        for (int num : nums) {
            sum += num;
            int target = sum - k;
            if (m.find(target) != m.end()) {
                res += m[target];
            }
            ++m[sum];
        }
        //if (sum == k) ++res;
        return res;
    }
};