class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), cmp);
        int st = 0, res = 0;
        priority_queue<int, vector<int>, greater<int>> q;
        for (vector<int> c :  courses) {
            st += c[0];
            ++res;
            q.push(-c[0]);
            while (st > c[1]) {
                st += q.top();
                q.pop();
                --res;
            }
        }
        return res;
    }
private:
    static bool cmp(vector<int>& a1, vector<int>& a2) {
        return a1[1] < a2[1];
    }
};