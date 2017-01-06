class Solution {
public:
    string intToRoman(int num) {
        vector<int> nums =    {1,   5,  10,  50,  100, 500, 1000};
        vector<char> Roman = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        string ans;
        int i = (int)nums.size() - 1;
        while (num > 0 && i >= 0) {
            if (num >= nums[i]) {
                if (i == nums.size() - 1) {
                    ans += Roman[i];
                    num -= nums[i];
                } else if (num >= nums[i + 1] - nums[(i + 1) - ((i + 1) % 2 ? 1 : 2)]) {
                    ans += Roman[i + 1 - ((i + 1) % 2 ? 1 : 2)];
                    ans += Roman[i + 1];
                    num -= nums[i + 1] - nums[i + 1 - ((i + 1) % 2 ? 1 : 2)];
                } else {
                    ans += Roman[i];
                    num -= nums[i];
                }
            } else {
                --i;
            }
        }
        return ans;
    }
};
