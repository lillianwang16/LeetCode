class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        bool ans = false;
        vector<int> char_num(26, 0);
        for (unsigned int i = 0; i <  ransomNote.length(); ++i) {
            ++char_num[ransomNote[i] - 'a'];
        }
        for (unsigned int i = 0; i <  magazine.length(); ++i) {
            if (char_num[magazine[i] - 'a']) {
                --char_num[magazine[i] - 'a'];
            }
        }
        if (!accumulate(char_num.begin(), char_num.end(), 0)) {
            ans = true;
        }
        return ans;
    }
};
