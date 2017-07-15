class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.size() < 1)    return res;
        int st = nums[0], cnt = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                ++cnt;
            } else {
                if (cnt == 1) {
                    res.push_back(to_string(st));
                    st = nums[i];
                } else {
                    string str;
                    str = to_string(st) + "->" + to_string(nums[i - 1]);
                    res.push_back(str);
                    cnt = 1;
                    st = nums[i];
                }
            }
        }
        if (cnt == 1) {
            res.push_back(to_string(st));
        } else {
            string str;
            str = to_string(st) + "->" + to_string(nums[nums.size() - 1]);
            res.push_back(str);
        }
        return res;
    }
};