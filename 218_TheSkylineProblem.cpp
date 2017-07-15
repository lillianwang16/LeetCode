/*
// Using map and check current res. 
class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> res;
        for (vector<int> r : buildings) {
            lines.push_back(line(r[0], r[2], 1));
            lines.push_back(line(r[1], r[2], -1));
        }
        sort(lines.begin(), lines.end(), cmp);
        map<int, int> cur;
        cur[0] = 1;
        res.push_back(make_pair(-1, 0));
        for (line l : lines) {
            if (l.type == 1) {
                ++cur[l.y];
                if (res.rbegin()->second < l.y) {
                    if (res.rbegin()->first == l.x) {
                        res.pop_back();
                    }
                    if (res.rbegin()->second != l.y) {
                        res.push_back(make_pair(l.x, l.y));
                    }
                }
            } else {
                --cur[l.y];
                if (cur[l.y] == 0) {
                    cur.erase(l.y);
                }
                if (cur.find(res.rbegin()->second) == cur.end()) {
                    if (res.rbegin()->first == l.x) {
                        res.pop_back();
                    }
                    if (res.rbegin()->second != cur.rbegin()->first) {
                        res.push_back(make_pair(l.x, cur.rbegin()->first));
                    }
                }
            }
        }
        res.erase(res.begin());
        return res;
    }
private:
    struct line {
        int x, y;
        int type;
        line(int xx, int yy, int tt): x(xx), y(yy), type(tt){}
    };
    static bool cmp(line a, line b) {
        return a.x < b.x;
    }
    vector<line> lines;
};
*/
class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> res;
        vector<pair<int, int>> lines;
        for (vector<int> r : buildings) {
            lines.push_back({r[0], -r[2]});// The minus is important here. 
                                           //It makes sure that lines with same x will insert the highest first and erase the highest last.
            lines.push_back({r[1], r[2]});
        }
        sort(lines.begin(), lines.end());
        multiset<int> height; // Multiset, always have the sorted order.
        height.insert(0);
        int pre = 0, cur = 0;
        for (pair<int, int> l : lines) {
            if (l.second < 0) {
                height.insert(-l.second);
            } else {
                height.erase(height.find(l.second));
            }
            cur =  *height.rbegin();
            if (pre != cur) {
                res.push_back({l.first, cur});
                pre = cur;
            }
        }
        return res;
    }
};
/*
// Use map. Same idea of using multiset and -height.
class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> res;
        for (vector<int> r : buildings) {
            lines.push_back(line(r[0], r[2], 1));
            lines.push_back(line(r[1], r[2], -1));
        }
        sort(lines.begin(), lines.end(), cmp);
        map<int, int> cur;
        cur[0] = 1;
        int pre = 0, now = 0;
        for (line l : lines) {
            if (l.type == 1) {
                ++cur[l.y];
            } else {
                --cur[l.y];
                if (cur[l.y] == 0) {
                    cur.erase(l.y);
                }
            }
            now =  cur.rbegin()->first;
            if (now != pre) {
                res.push_back({l.x, now});
                pre = now;
            }
        }
        return res;
    }
private:
    struct line {
        int x, y;
        int type;
        line(int xx, int yy, int tt): x(xx), y(yy), type(tt){}
    };
    static bool cmp(line a, line b) {
        if (a.x == b.x) {
            if (a.type == 1 && b.type == 1) {
                return a.y > b.y;
            } else if (a.type == -1 && b.type == -1) {
                return a.y < b.y;
            } else {
                return a.type == 1;
            }
        }
        return a.x < b.x;
    }
    vector<line> lines;
};
