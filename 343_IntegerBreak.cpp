class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) {
            return 1;
        }
        if (n == 3) {
            return 2;
        }
        /*
        int remainder = n % 3;
        if (remainder == 0) {
            return pow(3, n / 3);
        }
        if (remainder == 1) {
            return pow(3, n / 3 - 1) * 2 * 2;
        }
        if (remainder == 2) {
            return pow(3, n / 3) * 2;
        }
        if (remainder == 0) {
            return pow(3, n / 3);
        }
        return 0;
        */
        int ans = 1;
        while (n > 4) {
            ans *= 3;
            n -= 3;
        }
        return ans * n;
        
    }
};
