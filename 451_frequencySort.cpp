class Solution {
public:
    string frequencySort(string s) {
        vector<pair<char, int>> map_char;
        for (int i = 0; i < 256; ++i){
            map_char.push_back(make_pair(i, 0));
        }
        for (char c : s) {
            ++map_char[c].second;
        }
        sort(map_char.begin(), map_char.end(), comp);
        unsigned int i = 0;
        string ans;
        while (i < map_char.size() && map_char[i].second > 0) {
            for (int j = 0; j < map_char[i].second; ++j) {
                ans += map_char[i].first;
            }
            ++i;
        }
        return ans;
    }
private:
    static bool comp(const pair<char, int>& a, const pair<char, int>& b) {
        return (a.second > b.second);
    }
};

