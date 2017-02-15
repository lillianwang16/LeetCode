/*
// using + - * to seperate input to two substr
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        for (int i = 0; i < input.length(); ++i) {
            char c = input[i];
            if (c == '+' || c == '-' || c == '*') {
                vector<int> result1 = diffWaysToCompute(input.substr(0, i));
                vector<int> result2 = diffWaysToCompute(input.substr(i + 1));
                for (int num1 : result1) {
                    for (int num2 : result2) {
                        if (c == '+') {
                            result.push_back(num1 + num2);
                        } else if (c == '-') {
                            result.push_back(num1 - num2);
                        } else {
                            result.push_back(num1 * num2);
                        }
                    }
                }
            }
        }
        if (result.size() == 0) {
            result.push_back(atoi(input.c_str()));
        }
        return result;
    }
};
*/

// using a map for records
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        unordered_map<string, vector<int>> mapRe;
        return diffWaysToCompute(input, mapRe);
    }
private:
    vector<int> diffWaysToCompute(string input, unordered_map<string, vector<int>>& mapRe) {
        vector<int> result;
        for (int i = 0; i < input.length(); ++i) {
            char c = input[i];
            if (c == '+' || c == '-' || c == '*') {
                string str1 = input.substr(0, i);
                string str2 = input.substr(i + 1);
                vector<int> result1;
                vector<int> result2;
                if (mapRe.find(str1) != mapRe.end()) {
                    result1 = mapRe[str1];
                } else {
                    result1 = diffWaysToCompute(str1, mapRe);
                }
                if (mapRe.find(str2) != mapRe.end()) {
                    result2 = mapRe[str2];
                } else {
                    result2 = diffWaysToCompute(str2, mapRe);
                }
                for (int num1 : result1) {
                    for (int num2 : result2) {
                        if (c == '+') {
                            result.push_back(num1 + num2);
                        } else if (c == '-') {
                            result.push_back(num1 - num2);
                        } else {
                            result.push_back(num1 * num2);
                        }
                    }
                }
            }
        }
        if (result.empty()) {
            result.push_back(atoi(input.c_str()));
        }
        mapRe[input] = result;
        return result;
    }
};

