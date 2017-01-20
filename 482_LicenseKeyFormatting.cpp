class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int i = 0;
        while(i < S.length()) {
            if (S[i] == '-') {
                S.erase(i, 1);
            } else {
                if (S[i] >= 'a' && S[i] <= 'z') {
                    S[i] += 'A' - 'a'; 
                }
                ++i;
            }
        }
        int n = S.length() % K;
        i  = (n == 0 ? K : n);
        string dash = "-";  
        while (i < S.length()) {
            S.insert(i, dash);
            i += K;
            ++i;
        }
        return S;
    }
};
