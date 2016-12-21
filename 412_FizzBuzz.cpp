class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result(n);
        for(int i = 1; i <= n; ++i){
            if(i % 3 == 0){
                result[i - 1] += "Fizz";
            }
            if(i % 5 == 0){
                result[i - 1] += "Buzz";
            }
            if(i % 3 && i % 5){
                result[i - 1] += to_string(i); 
            }
        }
        return result;
    }
};
