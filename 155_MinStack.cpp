/*
// Using two vectors.
class MinStack {
public:
    // initialize your data structure here.
    MinStack() {
    
    }
    
    void push(int x) {
        my_stack_.push_back(x);
        if (min_pointer_.empty() || x < my_stack_[min_pointer_.back()]) {
            min_pointer_.push_back(my_stack_.size() - 1);
        }
    }
    
    void pop() {
        my_stack_.pop_back();
        if (min_pointer_.back() == my_stack_.size())
            min_pointer_.pop_back();
    }
    
    int top() {
        return my_stack_.back();
    }
    
    int getMin() {
        return my_stack_[min_pointer_.back()];
    }
private:
    vector<int> my_stack_;
    vector<int> min_pointer_;
    
};
*/
// Using only one stack.
class MinStack {
public:
    // initialize your data structure here.
    MinStack() {
    
    }
    
    void push(int x) {
       if (x <= min) {
           my_stack_.push(min);
           min = x;
       }
       my_stack_.push(x);
    }
    
    void pop() {
       int cur = my_stack_.top(); 
       my_stack_.pop();
       if (cur == min) {
           min = my_stack_.top();
           my_stack_.pop();
       }
    }
    
    int top() {
        return my_stack_.top();
    }
    
    int getMin() {
        return min;
    }
private:
    stack<int> my_stack_;
    int min = INT_MAX;
};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
