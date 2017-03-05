/*
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        double ans = 1;
        bool sign = (n > 0);
        long long nn = sign ? n : 0 - (long long)n;
        bool odd = (nn % 2) && nn != 1;
        while (nn > 0) {
            int cnt = 1;
            double temp = x;
            while (cnt < 31 && nn >= (1 << cnt)) {
                temp *= temp;
                ++cnt;
            }
            --cnt;
            ans *= temp;
            nn -= (1 << cnt);
        }
        return sign ? ans : 1.0 / ans ;
    }
};
*/
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        if (x == 0) {
            return 0;
        }
        if (n == INT_MIN) {
            return (1 / x) * myPow(x, ++n);
        }
        if (n < 0) {
            x = 1 / x;
            n = -n;
        }
        return (n % 2 == 0) ? myPow(x * x ,n / 2) : x * myPow(x * x, n / 2);
    }
};
