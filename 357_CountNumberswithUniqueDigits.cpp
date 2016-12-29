class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        }
        int res = 10;
        int n_number = 9;
        int available = 9;
        while (n > 1 && available >= 0) {
            n_number = n_number * available;
            res += n_number;
            --available;
            --n;
        }
        return res;
    }
};
