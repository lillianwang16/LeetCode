class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        vector<int> map_num(26);
        map_num['I' - 'A'] = 1;
        map_num['V' - 'A'] = 5;
        map_num['X' - 'A'] = 10;
        map_num['L' - 'A'] = 50;
        map_num['C' - 'A'] = 100;
        map_num['D' - 'A'] = 500;
        map_num['M' - 'A'] = 1000;
        for (size_t i = 1; i < s.length(); ++i) {
            if (map_num[s[i - 1] - 'A'] < map_num[s[i] - 'A']) {
                sum -= map_num[s[i - 1] - 'A'];
            } else {
                sum += map_num[s[i - 1] - 'A'];
            }
        }
        return sum + map_num[s[s.length() - 1] - 'A'];
    }
};
