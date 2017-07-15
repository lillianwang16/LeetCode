/*
//Binary search at each row. O(mn) complexity.
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        int lo = 0, hi = matrix[0].size() - 1;
        for (int i = 0; i < matrix.size(); ++i) {
            if (hi < 0) return false;
            lo = 0;
            while (hi >= lo) {
                int mid = (hi + lo + 1) / 2;
                int num = matrix[i][mid];
                if (num == target) {
                    return true;
                } else if (num < target) {
                    if (hi == lo) break;
                    lo = mid;
                } else {
                    hi = mid - 1;
                }
            }
        }
        return false;
    }
};
*/

//Start at the top right corner. Only O(m + n) complexity.
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        int row = 0, col = matrix[0].size() - 1;
        while (row < matrix.size() && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] < target) {
                ++row;
            } else if (matrix[row][col] > target) {
                --col;
            }
        }
        return false;
    }
};