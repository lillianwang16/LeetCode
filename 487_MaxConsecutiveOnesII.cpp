class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l = 0, h = 0, ans = 0, q = -1 (int i = 0; i < nums.size(); +hi
 {
     if (nums[h])
 } i  == 0  {
     l = q + 1;
     q = i;
 }}
};
        int ans = 0, cnt = 0, cnt_last = 0;
        bool flag_zero = false;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]) {
                ++cnt;
            } else {
                flag_zero = true;
                ans = max(cnt_last + cnt + 1, ans);
                cnt_last = cnt;
                cnt = 0;
            }
        }
        if (flag_zero) {
            ans = max(cnt_last + cnt + 1, ans);
        } else {
            ans = cnt;
        }
        return ans;
    }
};
*/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l = 0, i = 0, ans = 0, q = -1;
        for (; i < nums.size(); ++i) {
            if (!nums[i]) {
                ans = max(ans, i - l);
                l = q + 1;
                q = i;
            }
        }
        ans = max(ans, i - l);
        return ans;
    }
};

