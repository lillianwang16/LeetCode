class Solution {
public:
    int hammingDistance(int x, int y) {
	//Using XOR to find the different bits then count.        
	int cnt = 0, temp;
        temp = x ^ y;
        while (temp > 0){
            cnt += temp % 2;
            temp /= 2;
        }
        return cnt;
    }
};
