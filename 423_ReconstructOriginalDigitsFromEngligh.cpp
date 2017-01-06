class Solution {
public:
    string originalDigits(string s) {
        vector<int> cnt(10);
        for (c : s) {
            if (c == 'z') ++cnt[0];
            if (c == 'w') ++cnt[2];
            if (c == 'u') ++cnt[4];
            if (c == 'x') ++cnt[6];
            if (c == 'g') ++cnt[8];
            if (c == 'o') ++cnt[1];
            if (c == 't') ++cnt[3];
            if (c == 'f') ++cnt[5];
            if (c == 'v') ++cnt[7];
            if (c == 'i') ++cnt[9];
        }
        cnt[1] -= cnt[0] + cnt[2] + cnt[4]; 
        cnt[3] -= cnt[2] + cnt[8];
        cnt[5] -= cnt[4];
        cnt[7] -= cnt[5];
        cnt[9] -= cnt[5] + cnt[6] +cnt[8];
        string str;
        for (int i = 0; i < 10; ++i) {
            char c = i + '0';
            str += string(cnt[i], c);
        }
        return str;
    }
};
