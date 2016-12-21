class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        /*
        int median = nums[nums.size() / 2];
        for (unsigned int i = 0; i < nums.size(); ++i) {
            cnt += abs(nums[i] - median);
        }
        */
        unsigned int i = 0, j = nums.size() - 1;
        while (j > i){
            cnt += nums[j] - nums[i];
            --j;
            ++i;
        }
        return cnt;
    }
};
