/*
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int res = 0;
        for (int i = 0; i < M.size(); ++i) {
            for (int j = 0; j < M.size(); ++j) {
                if (M[i][j] == 1) {
                    floodFill(M, i, j);
                    ++res;
                }
            }
        }
        return res;
    }
private:
    void floodFill(vector<vector<int>>& M, int i, int j) {
        M[i][j] = 0;
        M[j][i] = 0;
        for (int k = 0; k < M.size(); ++k) {
            if (M[i][k] == 1) {
                floodFill(M, k, i);
            }
        }
    }
};
*/
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        vector<bool> visited(M.size());
        int res = 0;
        for (int i = 0; i < M.size(); ++i) {
            if (!visited[i]) {
                DFS(M, visited, i);
                ++res;
            }
        }
        return res;
    }
private:
    void DFS(vector<vector<int>>& M, vector<bool>& visited, int i) {
        for (int j = 0; j <  M.size(); ++j) {
            if (M[i][j] == 1 && !visited[j]) {
                visited[j] = true;
                DFS(M, visited, j);
            }
        }
    }
};