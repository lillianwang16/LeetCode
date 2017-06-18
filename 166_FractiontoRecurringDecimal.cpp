class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        bool sign = numerator == 0 || !((numerator > 0) ^ (denominator > 0));
        long long numerator1 = labs(numerator);
        long long denominator1 = labs(denominator);
        long long num1 = numerator1 / denominator1;
        long long num2 = numerator1 % denominator1;
        string str1 = to_string(num1);
        if (num2 == 0) {
            return sign ? "" + to_string(num1) : "-" + to_string(num1);
        }
        str1 += '.';
        unordered_map<long long, int> m;
        string str2;
        int cnt = 1;
        while (num2 != 0) {
            if (m[num2] > 0) {
                str2.insert(m[num2] - 1, "(");
                str2 += ")";
                break;
            }
            m[num2] = cnt;
            ++cnt;
            num2 *= 10;
            long long num3 = num2 / denominator1;
            num2 %= denominator1;
            str2 += to_string(num3);
        }
        return sign ? "" + str1 + str2 : "-" + str1 + str2;
    }
};
