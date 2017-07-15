class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.size() == 0) {
            return 0;
        }
        stack<int> st;
        for (string str : tokens) {
            int a;
            int b;
            if (str == "+") {
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                st.push(a + b);
                continue;
            } else if (str == "-") {
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                st.push(b - a);    
                continue;
            } else if (str == "*") {
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                st.push(a * b); 
                continue;
            } else if (str == "/") {    
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                st.push(b / a);
                continue;
            } else {
                st.push(atoi(str.c_str()));
            }
        }
        return st.top();
    }
};