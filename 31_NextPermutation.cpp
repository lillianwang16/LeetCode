class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1)   return;
        map<int, int> m;
        int i = nums.size() - 1;
        m[nums[i]] = i;
        --i;
        for (; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                int p = m.upper_bound(nums[i])->second;
                swap(nums[i], nums[p]);
                ++i;
                break;
            }
            m[nums[i]] = i;
        }
        sort(nums.begin() + i, nums.end());
    }
};

/*
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1)   return;
        int i = nums.size() - 2;
        for (; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                for (int j = nums.size() - 1; j > i; --j) {
                    if (nums[j] > nums[i]) {
                        swap(nums[i], nums[j]);
                        break;
                    }
                }
                ++i;
                break;
            }
        }
        i = max(0, i);
        sortReverse(nums, i, nums.size() - 1);
    }
private:
    void sortReverse(vector<int>& nums, int start, int end) {
        for (int i = start; i <= (start + end) / 2; ++i) {
            swap(nums[i], nums[start + end - i]);
        }
    }
};
*/