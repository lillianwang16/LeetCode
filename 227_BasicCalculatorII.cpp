/*
//Compute all * and / first.
class Solution {
public:
    int calculate(string s) {
        string s1;
        int j = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '*' || s[i] == '/') {
                string s2;
                int k = i + 1;
                if (s1 == "") {
                    j = i - 1;
                    while (j >= 0 && ((s[j] <= '9' && s[j] >= '0') || s[j] == ' ')) {
                        if (s[j] ==  ' ') {
                            --j;
                            continue;
                        }
                        s1 = s[j] + s1;
                        --j;
                    }
                }
                while (k < s.length() && ((s[k] <= '9' && s[k] >= '0') || s[k] == ' ')) {
                    if (s[k] ==  ' ') {
                        ++k;
                        continue;
                    }
                    s2 = s2 + s[k];
                    ++k;
                }
                long long a1 = atoll(s1.c_str()), a2 = atoll(s2.c_str());
                if (s[i] == '*') {
                    a1 *= a2;
                } else {
                    a1 /= a2;
                }
                s1 = to_string(a1);
                if (s[k] == '+' || s[k] == '-' || k == s.length()) {
                    s.replace(j + 1, k - j - 1, to_string(a1));
                    i = 0;
                    s1 = "";
                }
            }
        }
        long long a1;
        int i = 0;
        s1 = "";
        for (; i < s.length(); ++i) {
            if (s[i] == '+' || s[i] == '-') {
                break;
            }
            if (s[i] != ' ') {
                s1 += s[i];
            }
        }
        a1 = atoll(s1.c_str());
        bool sign;
        if (i != s.length()) {
            sign = s[i] == '+';
            ++i;
        }
        s1 = "";
        for (; i < s.length(); ++i) {
            if (s[i] == '+' || s[i] == '-') {
                if (sign) {
                    a1 += atoll(s1.c_str());
                } else {
                    a1 -= atoll(s1.c_str());
                }
                s1 = "";
                sign = s[i] == '+';
                continue;
            } else if (s[i] >= '0' && s[i] <= '9') {
                s1 += s[i]; 
            }
        }
        if (s1 != "") {
            if (sign) {
                a1 += atoll(s1.c_str());
            } else {
                a1 -= atoll(s1.c_str());
            }
        }
        return (int)a1;
    }
};
*/

// Using a stack.
class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        if (s.length() == 0) {
            return 0;
        }
        char sign = '+';
        int num = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + s[i] - '0';
            } 
            if ((s[i] < '0' && s[i] != ' ') || i == s.length() - 1) {
                if (sign == '+') {
                    st.push(num);
                }
                if (sign == '-') {
                    st.push(-num);
                }
                if (sign == '*') {
                    int temp = st.top() * num;
                    st.pop();
                    st.push(temp);
                }
                if (sign == '/') {
                    int temp = st.top() / num;
                    st.pop();
                    st.push(temp);
                }
                num = 0;
                sign = s[i];
            }
        }
        int res = 0;
        while (!st.empty()) {
            int i = st.top();
            st.pop();
            res += i;
        }
        return res;
    }
};
