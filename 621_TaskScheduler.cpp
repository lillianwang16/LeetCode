class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> m;
        for (char c : tasks) {
            ++m[c];
        }
        int mt = 0, cnt = 0;
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (mt < it->second) {
                mt = it->second;
                cnt = 1;
            } else if (mt == it->second) {
                ++cnt;
            }
        }
        return max((mt - 1) * (n + 1) + cnt, (int)tasks.size());
    }
};