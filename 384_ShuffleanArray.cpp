class Solution {
public:
    Solution(vector<int> nums): origin(nums){
        
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return origin;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        size_t len = origin.size();
        vector<int> shuffle_ans(origin);
        for (int i = 0; i < len; ++i) {
            int rand_num = rand() % (len - i);
            int temp = shuffle_ans[i];
            shuffle_ans[i] = shuffle_ans[i + rand_num];
            shuffle_ans[i + rand_num] = temp;
        }
        return shuffle_ans;
    }
private:
    vector<int> origin;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
