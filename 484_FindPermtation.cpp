/*
// When we find D, we reverse the nums.
class Solution {
public:
    vector<int> findPermutation(string s) {
        vector<int> nums;
        for (int i = 1; i <= s.length() + 1; ++i) {
            nums.push_back(i);
        }
        int st = 0, en = 0;
        while (en < s.length()) {
            if (s[en == 'D']) {
                st = en;
                while (en < s.length() && s[en] == 'D') {
                    ++en;
                }
                reverse(nums.begin() + st, nums.begin() + en + 1);
            }
           ++en;    
        }
        return nums;
    }
};
*/

/*
class Solution {
public:
    vector<int> findPermutation(string s) {
        vector<int> nums(s.length() + 1);
        nums[0] = 1;
        int i = 0;
        while (i < s.length()) {
            while (i < s.length() && s[i] == 'I') {
                nums[i + 1] = i + 2;
                ++i;
            }
            int cnt_D = i;
            while (cnt_D < s.length() && s[cnt_D] == 'D') {
                ++cnt_D;
            }
            int j = 0;
            while (i <= cnt_D) {
                nums[i] = cnt_D + 1 - j;
                ++j;
                if (i == cnt_D)
                    break;
                ++i;
            }
        }
        return nums;
    }
};
*/
class Solution {
public:
    vector<int> findPermutation(string s) {
        vector<int> nums;
        for (int i = 0; i <= s.length(); ++i) {
            if (i == s.length() || s[i] == 'I') {
                for (int j = i + 1, nums_s = nums.size(); j > nums_s; --j) {
                    nums.push_back(j);
                }
            }
        }
        return nums;
    }
};

