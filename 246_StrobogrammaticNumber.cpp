class Solution {
public:
    bool isStrobogrammatic(string num) {
        vector<int> rotate(10);
        rotate[0] = 0;
        rotate[1] = 1;
        rotate[6] = 9;
        rotate[8] = 8;
        rotate[9] = 6;
        for (int i = 0; i < num.length(); ++i) {
            if (rotate[num[i] - '0'] != num[num.length() - 1 - i] - '0') {
                return false;
            }
        }
        return true;
    }
};


