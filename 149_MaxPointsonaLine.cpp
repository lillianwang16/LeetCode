/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
 
 //Two dimension unordered_map.
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if (points.size() < 2) {
            return points.size();
        }
        int res = 0;
        for (int i = 0; i < points.size(); ++i) {
            unordered_map<int, unordered_map<int, int>> m;
            int overlap = 0;
            int local_max = 0, vertical = 0;
            for (int j = i + 1; j < points.size(); ++j ) {
                int dvd = points[j].y - points[i].y;
                int dvs = points[j].x - points[i].x;
                if (dvd == 0 && dvs == 0) {
                    ++overlap;
                    continue;
                } else {
                    int f = gcd(dvd, dvs);
                    dvd /= f;
                    dvs /= f;
                    if (m.find(dvd) == m.end()) {
                        unordered_map<int, int> m_dvd;
                        ++m_dvd[dvs];
                        m[dvd] = m_dvd;
                    } else {
                        ++m[dvd][dvs];
                    }
                }
                local_max = max(local_max, m[dvd][dvs]);
            }
            res = max(res, local_max + overlap + 1);
        }
        return res;
    }

private:
//gcd: can handle both (x, 0), (0, x) cases.
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        int temp = a % b;
        return gcd(b, temp);
    }
};