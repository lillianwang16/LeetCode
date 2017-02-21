/*
class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN) {
            return 0;
        }
        int ans = 0;
        int sign = x >> 31;
        x = abs(x);
        while (x > 0) {
            int temp = x % 10;
            if (ans > INT_MAX / 10 || (ans == INT_MAX /10 && temp > 7)) {
                return 0;
            }
            ans = ans * 10 + temp;
            x /= 10;
        }
        if (sign) 
            return -ans;
        return ans;
    }
};
*/
class Solution {
public:
    int reverse(int x) {
       int ans = 0;
       while (x) {
           int temp = ans * 10 + x % 10;
           if (temp / 10 != ans) {
               return 0;
           }
           ans = temp;
           x /= 10;
       }
       return ans;
    }
};
