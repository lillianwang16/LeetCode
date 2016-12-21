class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result;
        result.push_back(0);
        if (num == 0){
            return result;
        }
        result.push_back(1);
        if (num == 1){
            return result;
        }
        int pace = 1;
        for (int i = 2; i <= num; ++i){
            if (i == pace * 2){
                pace *= 2;
            }
            result.push_back(1 + result[i - pace]);
        }
        return result;
    }
};
