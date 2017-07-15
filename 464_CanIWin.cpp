// Using bit to store the current state.
class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal > (maxChoosableInteger + 1) * (maxChoosableInteger) / 2 )  return false;
        if (desiredTotal <= 0)  return true;
        used = vector<bool> (maxChoosableInteger + 1);
        return canIWin(desiredTotal);
    }
private:
    vector<bool> used;
    unordered_map<int, bool> m;

    bool canIWin(int total) {
        if (total <= 0) return false;
        int cur = format();
        if (m.find(cur) == m.end()) {
            for (int i = 1; i < used.size(); ++i) {
                if (!used[i]) {
                    used[i] = true;
                    if (!canIWin(total - i))  {
                        m[cur] = true;
                        used[i] = false;
                        return true;
                    }
                    used[i] = false;
                }
            }
            m[cur] = false;
        }
        return m[cur];
    }
    
    int format() {
        int temp = 0;
        int n = used.size();
        for (int i = 0; i < n; ++i) {
            if (used[i]) {
                temp |= (1 << (n - i - 1));
            }
        }
        return temp;
    }
};