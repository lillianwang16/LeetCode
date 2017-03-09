/*
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int ans = 0;
        int i = 0;
        heights.push_back(0);
        while (i < heights.size()) {
            int cnt = 1;
            while (!s.empty() && s.top() > heights[i]) {
                int temp = s.top();
                s.pop();
                ans = max(ans, temp * cnt);
                ++cnt;
            }
            while (cnt > 1) {
                s.push(heights[i]);
                --cnt;
            }
            if (s.empty() || heights[i] >= s.top()) {
                s.push(heights[i]);
            }
            ++i;
        }
        return ans;
    }
};
*/
//When the width is relative to the index, can puth the index in the stack other than the value.
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int ans = 0;
        int i = 0;
        heights.push_back(0);
        while (i < heights.size()) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                int k = s.top();
                s.pop();
                int left = s.empty() ? -1 : s.top();
                ans = max(ans, heights[k] * (i - 1 - left));
            }
            s.push(i);
            ++i;
        }
        return ans;
    }
};

