/*
// Convert every char to number for recording.
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string str;
        for (string i : strs) {
            for (char c : i) {
                 str += to_string((int) c) + '.';
            }
            str += '|';
        }
        return str;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        int cnt = 0;
        vector<string> strs;
        string str;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '|') {
                strs.push_back(str);
                str.erase();
            } else if (s[i] == '.'){
                char c = cnt;
                str += c;
                cnt = 0;
            } else {
                cnt = cnt * 10 + (s[i] - '0');
            }
        }
        return strs;
    }
};
*/
class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string str;
        for (string i : strs) {
            str += to_string(i.size()) + '.' + i;
        }
        return str;
    }


    // Decodes a single string to a list of strings.
    /*vector<string> decode(string s) {
        vector<string> strs;
        int i = 0;
        while (i < s.length()) {
            int dot_p = s.find('.', i);
            int len = stoi(s.substr(i, dot_p - i));
            i = dot_p + 1;
            strs.push_back(s.substr(i, len));
            i += len;
        }
        return strs;
    }
    */
        vector<string> decode(string s) {
        vector<string> r;
        int head = 0;
        while (head < s.size())    {
            int at_pos = s.find('.', head);
            int len = stoi(s.substr(head, at_pos - head));
            head = at_pos + 1;
            r.push_back(s.substr(head, len));
            head += len;
        }
        
        return r;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
