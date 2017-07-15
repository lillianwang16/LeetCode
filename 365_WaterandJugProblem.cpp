class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (z > x + y) return false;
        if (x % 2 + y % 2  < z % 2) return false;
        if (z == x || z == y || z == x + y)   return true;
        vector<bool> visited(max(x, y) + 1);
        visited[0] = true;
        visited[x] = true;
        visited[y] = true;
        queue<int> q;
        q.push(x);
        q.push(y);
        while (!q.empty()) {
            int temp = q.front();
            q.pop();
            int a = 0;
            if (temp < x) {
                a = y - (x - temp);
            } else {
                a = temp - x; 
            }
            if (a == z || a + x == z || a + y == z) return true;
            if (a > 0 && !visited[a]) {
                q.push(a);
                visited[a] = true;
            }
            if (temp < y) {
                a = x - (y - temp);
            } else {
                a = temp - y; 
            }
            if (a > 0 && !visited[a]) {
                q.push(a);
                visited[a] = true;
            }
            if (a == z || a + x == z || a + y == z) return true;
        }
        return false;
    }
};