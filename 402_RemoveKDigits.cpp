/*
class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.length() == k) {
            return "0";
        }
        string str = remove(num, k);
        for (int i = 0; i < str.length(); ++i) {
            if (str[i] != '0') {
                return str.substr(i, str.length());
            }
        }
        return "0";
    }
private:
    string remove(string num, int k) {
        if (num.length() == k)
            return "";
        if (k == 0)
            return num;
        string str;
        bool flag = false;
        for (int i = 0; i <= 9; ++i) {
            for (int j = 0; j <= k; ++j) {
                if (num[j] == '0' + i) {
                    str = to_string(i);
                    str += remove(num.substr(j + 1, num.length()), k - j);
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }
        return str;
    }
};
*/
class Solution {
public:
    string removeKdigits(string num, int k) {
        string res;
        int digits = num.length() - k;
        for (int i = 0; i < num.length(); ++i) {
            while (res.length() > 0 && k > 0 && res.back() > num[i]) {
                res.pop_back();
                --k;
            }
            res.push_back(num[i]);
        }
        res = res.substr(0, digits);
        for (int i = 0; i < res.length(); ++i) {
            if (res[i] != '0') {
                return res.substr(i, res.length());
            }
        }
        return "0";
    }
};