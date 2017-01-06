class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        vector<int> sum1;
        vector<int> sum2;
        for (size_t i = 0; i < A.size(); ++i) {
            for (size_t j = 0; j < A.size(); ++j) {
                sum1.push_back(A[i] + B[j]);
                sum2.push_back(C[i] + D[j]);
            }
        }
        sort(sum1.begin(), sum1.end());
        sort(sum2.begin(), sum2.end());
        int i = 0, j = (int)sum1.size() - 1;
        int cnt = 0;
        while (i < sum1.size() && j >= 0) {
            int sum4 = sum1[i] + sum2[j];
            if (sum4 == 0) {
                int cnt1 = 1, cnt2 = 1;
                ++i;
                while (i <= sum1.size() - 1 && sum1[i] == sum1[i - 1]) {
                    ++i;
                    ++cnt1;
                }
                --j;
                while (j >= 0 && sum2[j] == sum2[j + 1]) {
                    --j;
                    ++cnt2;
                }
                cnt += cnt1 * cnt2;
            } else if (sum4 > 0) {
                --j;
            } else {
                ++i;
            }
        }
        return cnt;
    }
};
