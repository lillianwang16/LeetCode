class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) {
            return INT_MAX;
        }
        bool sign = (dividend > 0) ^ (divisor > 0);
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        int res = 0;
        long long temp = dvs, cnt = 0;
        while (dvd >= (temp << 1)) {
            temp <<= 1;
            ++cnt;
        }
        while (cnt >= 0) {
            if (dvd >= dvs << cnt) {
                res += 1 << cnt;
                dvd -= dvs << cnt;
            }
            --cnt;
        }
        return sign ? -res : res;
    }
};