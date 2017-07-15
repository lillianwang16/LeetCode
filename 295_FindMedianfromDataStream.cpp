class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (q2.empty()) {
            q2.push(num);
            return;
        }
        if (num > q2.top() || (!q1.empty() && num > q1.top())) {
            q2.push(num);
        }  else {
            q1.push(num);
        }
        if (q2.size() > q1.size() + 1) {
            q1.push(q2.top());
            q2.pop();
        } else if (q1.size() > q2.size()) {
            q2.push(q1.top());
            q1.pop();
        }
    }
    
    double findMedian() {
        if (q2.empty()) {
            return 0;
        }
        if (q2.size() == q1.size()) {
            return ((double)q1.top() + (double)q2.top()) / 2;
        }
        return (double)q2.top();
    }
private:
    priority_queue<int> q1;
    priority_queue<int, vector<int>, greater<int>> q2;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
