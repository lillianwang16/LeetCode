class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        size_ = size;
        for (int i = 0; i< size_; ++i) {
            rec_.push_back(0);
        }
    }
    
    double next(int val) {
        sum_ += val;
        sum_ -= rec_[cnt_ % size_];
        rec_[cnt_ % size_] = val;
        ++cnt_;
        return double(sum_) / (cnt_ < size_ ? cnt_ : size_);
    }
private:
    int cnt_ = 0, sum_ = 0, size_ = 0;
    vector<int> rec_;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
