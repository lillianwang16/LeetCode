ass Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if (points.size() == 0) return 0;
        sort(points.begin(), points.end(), cmp);
        int count = 1, arrow = points[0].second;
        for (size_t i = 1; i < points.size(); ++i) {
            if (points[i].first > arrow) {
                ++count;
                arrow = points[i].second;
            }
        }
        return count;
    }
    static bool cmp (const pair<int, int>& a, const pair<int, int>& b) {
        return a.second == b.second ? (a.first < b.first) : (a.second < b.second);
    }
};
