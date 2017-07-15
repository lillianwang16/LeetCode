/*class Solution {
public:
    int integerReplacement(int n) {
        if (n == 1 || n == -1) {
            return 0;
        }
        //cout << INT_MAX + 1;
        int cnt = 0;
        if ((n% 2) == 0) {
            cnt = 1 + integerReplacement(n /2 );
        } else {
            cnt = 2 + min(integerReplacement((n + 1)/2), integerReplacement((n - 1) /2));
        }
        return cnt;
    }
};
*/

class Solution {
public:
    int integerReplacement(int n) {
        if (n == INT_MAX)   return 32;
        int cnt = 0;
        while (n != 1) {
            if ((n & 1) == 0) {
                ++cnt;
            } else {
                if (n == 3 || ((n >> 1) & 1) == 0) {
                    --n;
                } else {
                    ++n;
                }
                cnt += 2;
            }
            n >>= 1;
        }   
        return cnt;
    }
};