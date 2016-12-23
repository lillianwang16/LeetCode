class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3) {
            return 0;
        } 
        int ans = 0, cnt = 0;
        for (unsigned int i = 2; i < A.size(); ++i) {
            if ((A[i] - A[i - 1]) == (A[i - 1] - A[i - 2])) {
                ans += ++cnt;
            } else {
                cnt = 0;
            }
        }
        return ans;
    }
};
