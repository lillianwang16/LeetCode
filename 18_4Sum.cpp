/*
//Backtracking. Time limit exceeded.
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if (nums.size() < 4) {
            return ans;
        }
        set<vector<int>> temp;
        vector<int> cur;
        fourSumHelper(nums, temp, target, -1, cur);
        set<vector<int>> temp2;
        for (vector<int> a : temp) {
            sort(a.begin(), a.end());
            temp2.insert(a);
        }
        for (vector<int> b : temp2) {
            ans.push_back(b);
        }
        return ans;
    }
private:
    void fourSumHelper(vector<int>& nums, set<vector<int>>& temp, int target, int p, vector<int>& cur) {
        if (cur.size() == 4) {
            int sum = 0;
            for (int i = 0; i < 4; ++i) {
                sum += cur[i];
            }
            if (sum == target) {
                temp.insert(cur);
            }
            return;
        }
        for (int i = p + 1; i < nums.size(); ++i) {
            cur.push_back(nums[i]);
            fourSumHelper(nums, temp, target, i, cur);
            cur.pop_back();
        }
    }
};
*/
//Two sum. Two pointers.
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if (nums.size() < 4) {
            return ans;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int target3 = target - nums[i];
            for (int j = i + 1; j < nums.size(); ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int target2 = target3 - nums[j];
                int first = j + 1;
                int last = nums.size() - 1;
                while (first < last) {
                    int sum = nums[first] + nums[last];
                    if (sum < target2) 
                        ++first;
                    if (sum > target2) 
                        --last;
                    if (sum == target2) {
                        vector<int> cur;
                        cur.push_back(nums[i]);
                        cur.push_back(nums[j]);
                        cur.push_back(nums[first]);
                        cur.push_back(nums[last]);
                        ans.push_back(cur);
                        ++first;
                        --last;
                        while (first < last && nums[first] == nums[first - 1]) ++first;
                        while (first < last && nums[last] == nums[last + 1]) --last;
                    }
                }
            }
        } 
        return ans;
    }
};
