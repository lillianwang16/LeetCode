class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int n = (int)points.size();
        vector<vector<int> > dis(n, vector<int> (n));
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int temp = (points[i].first - points[j].first) * (points[i].first - points[j].first) + (points[i].second - points[j].second) * (points[i].second - points[j].second);
                dis[i][j] = dis[j][i] = temp;
            }
        }
        for (int i = 0; i <n; ++i) {
            sort(dis[i].begin(), dis[i].end());
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            for (int j = 1; j < n; ++j) {
                if (dis[i][j - 1] == dis[i][j]) {
                    ++cnt;
                    ans += 2 * cnt;
                } else {
                    cnt = 0;
                }
            }
        }
        return ans;
    }
};
