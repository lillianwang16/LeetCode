class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        int i = 0;
        string str;
        while (i <= path.length()) {
            if (i == path.length() || path[i] == '/') {
                if (str.length() == 0 || str == ".") {
                    ++i;
                    str.clear();
                    continue;
                }
                if (str == "..") {
                    ++i;
                    if (!s.empty()) {
                        s.pop();
                    }
                    str.clear();
                    continue;
                }
                s.push(str);
                str.clear();
                continue;
                ++i;
            }
            if (i < path.length()) {
                str += path[i];
            }
            ++i;
        }
        str.clear();
        if (s.empty()) {
            return "/";
        } 
        while (!s.empty()) {
            string temp = s.top();
            s.pop();
            str = temp + str;
            str = "/" + str;
        }
        return str;
    }
};