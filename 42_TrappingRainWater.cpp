/*
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int ans = 0, i = 0; 
        while (i < height.size()) {
            if (st.empty() || height[i] <= st.top()) {
                st.push(height[i]);
                ++i;
            } else {
                int cur = st.top(), cnt = 1;
                st.pop();
                while (!st.empty() && st.top() == cur) {
                    ++cnt;
                    st.pop();
                } 
                if (!st.empty() && st.top() > cur) {
                    int pole = min(st.top(), height[i]);
                    ans += cnt * (pole - cur);
                    while (cnt) {
                        st.push(pole);
                        --cnt;
                    }
                }
            }
        }
        return ans;
    }
};
*/
class Solution {
public:
    int trap(vector<int>& height) {
       int leftMax = 0, rightMax = 0;
       int ans = 0;
       int left = 0, right = height.size() - 1;
       while (left < right) {
           if (height[left] <= height[right]) {
               if (height[left] >= leftMax) {
                   leftMax = height[left];
               } else {
                   ans += leftMax - height[left];
               }
               ++left;
           } else {
               if (height[right] >= rightMax) {
                   rightMax = height[right];
               } else {
                   ans += rightMax - height[right];
               }
               --right;
           }
       }
       return ans;
    }
};

