/*
//Using unordered map for search.
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            m[nums[i]] = true;
        }
        for (int i = 0; i < nums.size() ; ++i) {
            int cnt = 1;
            if (m[nums[i]]) {
                m.erase(nums[i]);
                search(nums[i] + 1, cnt);
                search(nums[i] - 1, cnt);
            }
            if (cnt > res) {
                res = cnt;
            }
        }
        return res;
    }
private:
    unordered_map<int, bool> m;
    void search(int target, int &cnt) {
        if (m[target]) {
            ++cnt;
            m.erase(target);
            search(target + 1, cnt);
            search(target - 1, cnt);
        }
    }
};
*/
//Another solution.
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> m;
        for (int n : nums) {
            if (m.find(n) == m.end()) {
                int left = (m.find(n - 1) == m.end()) ? 0 : m[n - 1];
                int right = (m.find(n + 1) == m.end()) ? 0 : m[n + 1];
                int sum = left + right + 1;
                res = max(sum, res);
                m[n] = sum;
                m[n - left] = sum;
                m[n + right] = sum;
            }
        }
        return res;
    }
};