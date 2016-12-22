ass Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> fre;
        for (unsigned int i = 0; i < nums.size(); ++i) {
            ++fre[nums[i]];
        }
        vector<int> ans;
        vector<pair<int, int>> fre_v;
        for (auto i : fre) {
            fre_v.push_back(make_pair(i.first, i.second));
        }
        sort(fre_v.begin(), fre_v.end(), comp);
        unsigned int i = 0;
        while (k > 0) {
            ans.push_back(fre_v[i].first);
            --k;
            ++i;
        }
        return ans;
    }
private:
    static bool comp(pair<int, int>& a, pair<int, int>& b) {
        return (a.second > b.second);
    }
};
