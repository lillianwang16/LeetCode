class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int F = 0, s = 0, len = A.size();
        for (int i = 0; i < len; ++i) {
            s += A[i];
            F += i * A[i];
        }
        int res = F;
        for (int i = len - 1; i > 0; --i) {
            F = F + s - len * A[i];
            res = max(res, F);
        }
        return res;
    }
};