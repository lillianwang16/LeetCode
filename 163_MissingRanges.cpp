class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ans;
        nums.insert(nums.begin(), lower);
        nums.push_back(upper);    
        for (int i = 0; i < nums.size() - 1; ++i) {
            int l = nums[i];
            int h = nums[i + 1];
            if (h <= l && nums.size() > 2) {continue;}
            ++l;
            --h;
            if (i == 0) --l; 
            if (i == nums.size() - 2) ++h; 
            string str, str2 = "->";
            if (h >= l)  str += to_string(l);
            if (h > l) {
                str += str2 + to_string(h);
            }
            if (str.length() > 0)  ans.push_back(str);
        }
        return ans;
    }
};
