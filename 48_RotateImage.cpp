/*
//straightforward method
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; ++i) {
            for (int j = i; j < n - i - 1; ++j) {
                int temp = matrix[i][j];
                for (int k = 0; k < 4; ++k) {
                    int index = i;
                    i = j;
                    j = n - index - 1;
                    int temp2 = matrix[i][j];
                    matrix[i][j] = temp;
                    temp = temp2;
                }
            }
        }
    }
};
*/
//flip and transpose
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = i + 1; j < matrix[0].size(); ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
