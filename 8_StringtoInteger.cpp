/*
class Solution {
public:
    int myAtoi(string str) {
        int sign = 0, cur = 0;
        long ans = 0;
        for (; cur < str.length(); ++cur) {
            if (str[cur] >= '0' && str[cur] <= '9') {
                break;
            } else if (str[cur] == ' ') {
                if (sign) {
                    return 0;
                } else {
                    continue;    
                }
            } else  if (str[cur] == '-' || str[cur] == '+') {
                if (sign) {
                    return 0;
                }
                if (str[cur] == '-'){
                    sign = -1;
                } else if (str[cur] == '+') {
                    sign = 1;
                }
            } else {
                return 0;
            }
        }
        for (;cur < str.length(); ++cur) {
            if (str[cur] < '0' || str[cur] > '9' || ans > INT_MAX) {
                break;
            }
            ans = ans * 10 + str[cur] - '0';
        }
        if (sign == -1) {
            return (ans <= INT_MAX ? (int)-ans : INT_MIN);
        }
        return (ans < INT_MAX ? (int)ans : INT_MAX);
    }
};
*/
class Solution {
public:
    int myAtoi(string str) {
        int sign = 1, cur = 0, ans = 0;
        while (cur < str.length() && str[cur] == ' ') {
            ++cur;
        }
        if (str[cur] == '+' || str[cur] == '-') {
            sign -= (str[cur++] - '+');
        }
        while (cur < str.length() && str[cur] >= '0' && str[cur] <= '9') {
            if (ans  > INT_MAX / 10 || (ans == INT_MAX / 10 && str[cur] - '0' > 7)) {
                if (sign == 1) {
                    return INT_MAX;
                } else {
                    return INT_MIN;
                }
            }
            ans = ans * 10 + (str[cur++] - '0');
        }
        return ans * sign;
    }
};
