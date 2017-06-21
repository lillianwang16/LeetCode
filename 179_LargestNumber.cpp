class Solution {
public:
    string largestNumber(vector<int>& nums) {
        bool flag = false;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                flag = true;
            }
        }
        if (!flag) {
            return "0";
        }
        vector<string> nums_str;
        for (int num : nums) {
            nums_str.push_back(to_string(num));
        }
        sort(nums_str.begin(), nums_str.end(), cmp);
        string res;
        for (int i = 0; i < nums.size(); ++i) {
            res += nums_str[i];
        }
        return res;
    }
private:
/*
// Recursive cmp by compare each bit.
    static bool cmp(string& a, string& b) {
        int m = a.length(), n = b.length(), i = 0;
        while (i < m && i < n) {
            if (a[i] > b[i]) {
                return true;
            } else if (a[i] < b[i]) {
                return false;
            }
            ++i;
        }
        if (i == m && i == n) {
            return false;
        } else if (i == m) {
            string bb = b.substr(i);
            return cmp(a, bb);
        } else {
            string aa = a.substr(i);
            return cmp(aa, b);
        }
    }
 */
 // Add two string and compare.
    static bool cmp(string& a, string& b) {
        string str1 = a + b;
        string str2 = b + a;
        return (a + b) > (b + a);
    }
};
