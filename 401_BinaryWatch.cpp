/*
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> ans;
        if (num > 8) {
            return ans;
        }
        if (num == 0) {
            ans.push_back("0:00");
            return ans;
        }
        
        for (int k = max(0, num - 5); k <= 3 && k <= num; ++k)
        if (num - k <= 5) {
            vector<int> hour;
            vector<int> minute;
            nBitBinarySum(4, k, 0, 0, 0, hour);
            nBitBinarySum(6, num - k, 0, 0, 0, minute);
            for (int i = 0; i < hour.size(); ++i) {
                for (int j = 0; j < minute.size(); ++j) {
                    string temp;
                    if (hour[i] < 12 && minute[j] < 60) {
                        temp += to_string(hour[i]);
                        
                        temp += ':';
                        if (minute[j] < 10) {
                            temp += '0';
                            temp += to_string(minute[j]);
                        } else if (minute[j] < 60) {
                            temp += to_string(minute[j]);
                        }
                        ans.push_back(temp);
                    }
                }
            }
            hour.clear();
            minute.clear();
        }
        return ans;
    }
private:
    void nBitBinarySum(int bit_total, int bit, int step, int p, int sum, vector<int>& vec) {
        if (step >= bit) {
            vec.push_back(sum);
            return;
        }
        for (int i = p; i < bit_total; ++i) {
            sum += 1 << i;
            nBitBinarySum(bit_total, bit, step + 1, i + 1, sum, vec);
            sum -= 1 << i;
        }
    }
};
*/
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> ans;
        for (int h = 0; h < 12; ++h) {
            for (int minute = 0; minute < 60; ++minute) {
                if (bitset<10>(h << 6 | minute).count() == num) {
                    ans.push_back(to_string(h) + (minute < 10 ? ":0" : ":") + to_string(minute));
                }
            }
        }
        return ans;
    }
};



