class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n1 = INT_MAX, n2 = INT_MAX;
        for (int n : nums) {
            if (n1 >= n) {
                n1 = n;
            } else if (n2 >= n) {
                n2 = n;
            } else {
                return true;
            }
        }
        return false;
    }
};