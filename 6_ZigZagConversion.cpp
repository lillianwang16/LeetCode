//computing index
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) 
            return s;
        string str;
        int len = s.length();
        for (int i = 0; i < numRows; ++i) {
            int p = i;
            int step1 = 2 * (numRows - i - 1);
            while (p < len) {
                str += s[p];
                if (numRows > 2) {
                    if (i != 0 && i < numRows - 1 && p + step1 < len) {
                        str += s[p + step1];    
                    }
                     p += numRows - 2;
                }
                p += numRows;
            }
        }
        return str;
    }
};
/*
// simulate the zigzag
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) 
            return s;
        string ans;
        vector<string> str(numRows); 
        int step = 1, row = 0;
        for (int i = 0; i< s.length(); ++i) {
            str[row].push_back(s[i]);
            if (row == 0) 
                step = 1;
            if (row == numRows - 1) 
                step = -1;
            row += step;
        }
        for (int i = 0; i < numRows; ++i) {
            ans.append(str[i]);
        }
        return ans;
    }
}; 
*/
