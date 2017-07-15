class Solution {
public:
    bool isAdditiveNumber(string num) {
        if (num.length() < 3)   return false;
        bool res = false;
        vector<int> a;
        for (int i = 1; i < (num.length() + 1) / 2 + 1; ++i) {
            a.push_back(num[i - 1] - '0');
            vector<int> b;
            for (int j = i + 1; j <= (num.length() + 1) * 2 / 3; ++j) {
                if (num[i] == '0' && j - i > 1)  break;
                b.push_back(num[j - 1] - '0');
                res = res || isAdditive(num, j, a, b);
            }
        }
        return res;
    }
private:
    bool isAdditive(string num, int p, vector<int> a, vector<int> b){
        if (p == num.length())  return true;
        vector<int> c;
        int i = a.size() - 1, j = b.size() - 1, cnt = 0;
        while (i >= 0 || j >= 0 || cnt > 0) {
            int s = cnt + (i >= 0 ? a[i] : 0) + (j >= 0 ? b[j] : 0);
            c.push_back(s % 10);
            cnt = s / 10;
            --i;
            --j;
        }
        reverse(c.begin(), c.end());
        for (int i = 0; i < c.size(); ++i) {
            if (p + i >= num.length() || num[p + i] != '0' + c[i]) {
                return false;
            }
        }
        return isAdditive(num, p + c.size(), b, c);
    }
};