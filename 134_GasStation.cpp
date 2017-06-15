class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for (int i = 0; i < gas.size(); ++i) {
            gas[i] -= cost[i];
        }
        for (int i = 0; i < gas.size(); ++i) {
            if (gas[i] >= 0) {
                if (i == 0 || (i > 0 && gas[i - 1] <= 0)) {
                    int sum = 0;
                    bool flag = true;
                    for (int j = 0; j < gas.size(); ++j) {
                        sum += gas[(i + j) % gas.size()];
                        if (sum < 0) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) {
                        return i;
                    }
                }
            }
        }
        return -1;
    }
};