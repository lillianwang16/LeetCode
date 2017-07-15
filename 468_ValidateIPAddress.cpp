class Solution {
public:
    string validIPAddress(string IP) {
        bool IPv4 = false, IPv6 = false;
        for (int i = 0; i < IP.size(); ++i) {
            if (IP[i] == '.') {
                IPv4 = true;
                break;
            }
            if (IP[i] == ':') {
                IPv6 = true;
                break;
            }
        }
        if (!IPv4 && !IPv6) {
            return "Neither";
        }
        int cnt = 0;
        if (IPv4) {
            int i = 0;
            while (i < IP.size()) {
                int si = i;
                bool zero = false;
                if (IP[i] == '.') {
                    return "Neither";
                }
                if (IP[i] == '0') {
                    ++i;
                    zero = true;
                }
                while (i < IP.size() && IP[i] != '.') {
                    if (zero || IP[i] > '9' ||  IP[i] < '0') {
                        return "Neither";
                    }
                    ++i;
                }
                if (i - si > 3 || atoi(IP.substr(si, i - si).c_str()) > 255) {
                    return  "Neither";
                }
                if (i == IP.size() - 1 && IP[i] == '.') {
                    return "Neither";
                }
                ++cnt;
                ++i;
            }
        }
        if (IPv4 && cnt == 4) {
            return "IPv4";
        }
        if (IPv6) {
            int i = 0;
            while (i < IP.size()) {
                int cnt2 = 0;
                if (IP[i] == ':') {
                    return "Neither";
                }
                while (i < IP.size() && IP[i] != ':') {
                    if ((IP[i] >= 'A' && IP[i] <= 'F') || (IP[i] >= 'a' && IP[i] <= 'f') || (IP[i] >= '0' && IP[i] <= '9')) {
                        ++cnt2;
                        ++i;
                        continue;
                    }
                    return "Neither";
                }
                if (cnt2 > 4) {
                    return "Neither";
                }
                if (i == IP.size() - 1 && IP[i] == ':') {
                    return "Neither";
                }
                ++i;
                ++cnt;
            }
        }
        if (IPv6 && cnt == 8) {
            return "IPv6";
        }
        return "Neither";
    }
};