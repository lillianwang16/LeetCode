class Solution {
public:
    int climbStairs(int n) {
        int pre = 1, cur = 1;
        for (int i = 1; i < n; ++i) {
            int temp = pre + cur;
            pre = cur;
            cur = temp;
        }
        return cur;
    }
};
