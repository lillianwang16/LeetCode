/*
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> m;
        string str = s.substr(0, 10);
        m[str] = 1;
        for (int i = 10; i < s.length(); ++i) {
            str += s[i];
            str.erase(str.begin());
            m[str]++;
        }
        vector<string> res;
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it->second > 1) {
                res.push_back(it->first);
            }
        }
        return res;
    }
};
*/
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, int> m;
        vector<int> dir(26);
        dir['C' - 'A'] = 1;
        dir['G' - 'A'] = 2;
        dir['T' - 'A'] = 3;
        int code = 0;
        for (int i = 0; i < 10; ++i) {
            code <<= 3;
            code |= dir[s[i] - 'A'];
        }
        m[code]++;
        vector<string> res;
        for (int i = 10; i < s.length(); ++i) {
            code <<= 3;
            code &= 0x3FFFFFFF;
            code |= dir[s[i] - 'A'];
            if (m[code] == 1) {
                res.push_back(s.substr(i - 10 + 1, 10));
            }   
            m[code]++;
        } 
        return res;
    }
};