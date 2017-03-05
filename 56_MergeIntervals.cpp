/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool cmp(Interval a, Interval b) {
        return a.start < b.start;
}
    
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> merge_intervals;
        if (intervals.size() == 0) {
            return merge_intervals;
        }
        Interval cur;
        for (int i = 0; i < intervals.size(); ++i) {
            if (intervals[i].start <= cur.end) {
                cur.end = max(intervals[i].end, cur.end);
            } else {
                if (i > 0) {
                    merge_intervals.push_back(cur);
                }
                cur = intervals[i];
            }
        }
        merge_intervals.push_back(cur);
        return merge_intervals;
    }
};
