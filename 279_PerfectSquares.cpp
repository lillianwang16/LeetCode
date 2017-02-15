/*
// DP.
class Solution {
public:
    int numSquares(int n) {
        vector<int> f(n + 1, 0);
        f[0] = 0;
        for (int i = 1; i <= n; ++i) {
            int i_min = INT_MAX;
            for (int j = 1; j * j <= i; ++j) {
                i_min = min(i_min, f[i - j * j] + 1);
            }
            f[i] = i_min;
        }
        return f[n];
    }
};
*/


// Static DP.
class Solution {
public:
    int numSquares(int n) {
        if (n <= 0) 
            return 0;
        static vector<int> f({0});
        while (n >= f.size()) {
            int i = f.size(), i_min = INT_MAX;
            for (int j = 1; j * j <= i; ++j) {
                i_min = min(i_min, f[i - j * j] + 1);
            }
            f.push_back(i_min);
        }
        return f[n];
    }
};

/*
// BFS.
class Solution {
public:
    int numSquares(int n) {
        vector<bool> f(n + 1);
        vector<int> square;
        queue<int> cur_sum;
        for (int i = 1; i * i <= n; ++i) {
            if (n == i * i) 
                 return 1;
            square.push_back(i * i);
            cur_sum.push(i * i);
            f[i * i] = true;
        }
        int step = 1;
        while (!cur_sum.empty()) {
            int q_size = cur_sum.size();
            ++step;
            while (q_size > 0) {
                int cur = cur_sum.front();
                cur_sum.pop();  
                for (int i : square) {
                    int temp = cur + i;
                    if (temp == n) {
                        return step;
                    }
                    if (temp < n && !f[temp]) {
                        cur_sum.push(temp);
                    }
                }
                --q_size;                    
            }
        }
    }
};
*/
