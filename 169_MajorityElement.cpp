ass Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major_num, cnt = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (!cnt) {
                major_num = nums[i];
            }
            cnt += ((major_num == nums[i]) ? 1 : -1);
        }
        return major_num;
        /*
        nth_element(nums.begin(), nums.begin() + nums.size()/2, nums.end());
        return nums[nums.size() / 2];
        */
    }
};
