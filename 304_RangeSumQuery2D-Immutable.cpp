class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        int row = 0, col = 0;
        if (matrix.size() != 0 && matrix[0].size()) {
            row = matrix.size();
            col = matrix[0].size();
        }
        s = vector<vector<int>> (row + 1, vector<int> (col + 1, 0));
        for (int i = 1; i <= row; ++i) {
            int sum = 0;
            for (int j = 1; j <= col; ++j) {
                sum += matrix[i - 1][j - 1];
                s[i][j] = s[i - 1][j] + sum;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row2 > s.size() + 1 || col2 > s[0].size() + 1)  return 0;
        return s[row2 + 1][col2 + 1] - s[row1][col2 + 1] - s[row2 + 1][col1] + s[row1][col1];
    }
private:
    vector<vector<int>> s;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */