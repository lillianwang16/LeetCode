class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0, len1 = version1.length(), len2 = version2.length();
        while (i < len1 || j < len2) {
            int v1, v2;
            int s1 = i, s2 = j;
            while (i < len1 && version1[i] != '.') {
                ++i;
            }
            v1 = atoi(version1.substr(s1, i - s1).c_str());
            while (j < len2 && version2[j] != '.') {
                ++j;
            }
            v2 = atoi(version2.substr(s2, j - s2).c_str());
            //cout << v1 << ' ' << v2;
            if (v1 > v2) {
                return 1;
            }
            if (v1 < v2) {
                return -1;
            }
            if (i != len1) ++i;
            if (j != len2) ++j;
        }
        return 0;
    }
};