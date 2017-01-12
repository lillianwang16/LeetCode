/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        vector<int> ans;
        vector<pair<int, int> > intervals_index;
        int n = intervals.size();
        for (int i = 0; i < n; ++i) {
            intervals_index.push_back(make_pair(intervals[i].start, i));
        }
        sort(intervals_index.begin(), intervals_index.end(), cmp);
        for (int i = 0; i < n; ++i) {
            int p = binarySearch(intervals_index, intervals[i].end);
            ans.push_back(p);
        }
        return ans;
    }
    int binarySearch(vector<pair<int, int> >& intervals_index, int target) {
        int lo = 0, hi = intervals_index.size() - 1;
        if (intervals_index[hi].first < target) return -1;
        while (lo < hi) {
            int mid = (lo + hi) / 2, mid_num = intervals_index[mid].first;
            if (target == mid_num) {
                return intervals_index[mid].second;
            } else if (target < mid_num) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return intervals_index[lo].second;
    }
    static bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    }
};
