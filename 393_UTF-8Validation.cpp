class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int cnt = 0;
        for (int i = 0; i < data.size(); ++i) {
            if (cnt > 0) {
                if (calOnes(data[i]) != 1)  return false;
                else  --cnt;
            } else if (cnt == 0) {
                if (calOnes(data[i]) == 0)  continue;
                if (calOnes(data[i]) == 1)  return false;
                cnt = calOnes(data[i]) - 1;
            }
        }
        return cnt == 0;
    }
private:
    int calOnes(int a) {
        int cnt = 0;
        for (int i = 7; i > 0; --i) {
            if (a & (1 << i)) {
                ++cnt;
            } else  return cnt;
        }
        return cnt;
    }
};
