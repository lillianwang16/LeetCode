class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> rec;
        string str;
        generateParenthesis(n, 0, 0, 0, str, rec);
        return rec;
    }
private:
    void generateParenthesis(int n, int left_num, int right_num, int step, string& str, vector<string>& rec) {
        if (step == 2 * n) {
            rec.push_back(str);
        }
        if (left_num < n) {
            str += '(';
            generateParenthesis(n, left_num + 1, right_num, step + 1, str, rec); 
            str.pop_back();
        }
        if (right_num < left_num) {
            str += ')';
            generateParenthesis(n, left_num, right_num + 1, step + 1, str, rec); 
            str.pop_back();
        }
    }
};

