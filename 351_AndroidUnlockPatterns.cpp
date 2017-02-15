/*
//  Simulate the screen using a 2D vector and move around.
class Solution {
public:
    int numberOfPatterns(int m, int n) {
        vector<vector<int>> screen(3, vector<int>(3));
        int ans = 0;
        screen[0][0] = 1;
        numberOfPatterns(screen, m, n, 0, 0, 1, ans);
        screen[0][0] = 0;
        screen[1][0] = 1;
        numberOfPatterns(screen, m, n, 1, 0, 1, ans);
        screen[1][0] = 0;
        ans *= 4;
        screen[1][1] = 1;
        numberOfPatterns(screen, m, n, 1, 1, 1, ans);
        screen[1][1] = 0;
        return ans;
    }
private:
    vector<int> move_ = {0, 1, -1, 2, -2};
    void numberOfPatterns(vector<vector<int>>& screen, int m, int n, int x, int y, int step, int& ans) {
        if (step > n) 
            return;
        if (step >= m)
            ++ans;
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                int dx = move_[i];
                int dy = move_[j];
                if (x + dx < 3 && x + dx >= 0 && y + dy < 3 && y + dy >= 0) {
                    if (dx == 0 && (dy == 2 || dy == -2) && screen[x][1] != 1) continue;
                    if ((dx == 2 || dx == -2) && dy == 0 && screen[1][y] != 1) continue;
                    if ((dx == 2 || dx == -2) && (dy == 2 || dy == -2) && screen[1][1] != 1) continue;
                    if (!screen[x + dx][y + dy]) {
                        screen[x + dx][y + dy] = 1;
                        numberOfPatterns(screen, m, n, x + dx, y + dy, step + 1, ans);
                        screen[x + dx][y + dy] = 0;
                    }
                }
            }
        }
    }
};
*/

// Using a boolean vector to store the passed number.
class Solution {
public:
    int numberOfPatterns(int m, int n) {
        vector<vector<int>> skip(10, vector<int> (10));
        skip[1][3] = skip[3][1] = 2; 
        skip[7][9] = skip[9][7] = 8; 
        skip[1][7] = skip[7][1] = 4; 
        skip[3][9] = skip[9][3] = 6; 
        skip[1][9] = skip[9][1] = skip[3][7] = skip[7][3] = skip[2][8] = skip[8][2] = skip[4][6] = skip[6][4] = 5;
        int ans = 0;
        vector<bool> vis(10);
        numberOfPatterns(skip, vis, m, n, 1, 1, ans);
        numberOfPatterns(skip, vis, m, n, 2, 1, ans);
        ans *= 4;
        numberOfPatterns(skip, vis, m, n, 5, 1, ans);
        return ans;
    }

private:
    void numberOfPatterns(const vector<vector<int>>& skip, vector<bool>& vis, int m, int n, int cur, int step, int& ans) {
        if (step > n) 
            return;
        if (step >= m)
            ++ans;
        vis[cur] = true;
        for (int i = 1; i <= 9; ++i) {
            if (!vis[i] && (skip[cur][i] == 0 || vis[skip[cur][i]])) {
                numberOfPatterns(skip, vis, m, n, i, step + 1, ans);
            }
        }
        vis[cur] = false;
    }
};

