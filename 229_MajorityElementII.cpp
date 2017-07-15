class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnta = 0, cntb = 0, a = 0, b = 1; // Make sure a != b.
        for (int n : nums) {
            if (a == n) {
                ++cnta;
            } else if (b == n) {
                ++cntb;
            } else if (cnta == 0) {
                a = n;
                cnta = 1;
            } else if (cntb == 0) {
                b = n;
                cntb = 1;
            } else {
                --cnta;
                --cntb;
            }
        }
        cnta = 0;
        cntb = 0;
        for (int n : nums) {
            if (a == n) ++cnta;
            if (b == n) ++cntb;
        }
        vector<int> res;
        if (cnta > nums.size() / 3) {
            res.push_back(a);
        }
        if (cntb > nums.size() / 3) {
            res.push_back(b);
        }
        return res;
    }
};