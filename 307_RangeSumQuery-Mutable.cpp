/*
// Segment Tree.
class NumArray {
public:
    NumArray(vector<int> nums) {
        _root = buildTree(nums, 0, nums.size() - 1);
    }
    
    
    void update(int i, int val) {
        update(_root, i, val);
    }
    
    int sumRange(int i, int j) {
        return sumRange(_root, i, j);
    }
private:
    struct Node {
        int start, end;
        int sum;
        Node *left, *right;
        Node(int n1, int n2): start(n1), end(n2), sum(0),left(NULL), right(NULL) {}
    };
    Node *_root;
    Node* buildTree(vector<int>& nums, int start, int end) {
        if (start > end) {
            return NULL;
        }
        Node* cur = new Node(start, end);
        if (start == end) {
            cur->sum = nums[start];
            return cur;
        } else {
            int mid = (start + end) / 2;
            cur->left = buildTree(nums, start, mid);
            cur->right = buildTree(nums, mid + 1, end);
            cur->sum = cur->left->sum + cur->right->sum;
        }
        return cur;
    }
    void update(Node* cur, int i, int val) {
        if (cur == NULL || cur->start == cur->end) {
            cur->sum = val;
            return;
        } 
        int mid = (cur->start + cur->end) / 2;
        if (i <= mid) {
            update(cur->left, i, val);
        } else {
            update(cur->right, i, val);
        }
        cur->sum = cur->left->sum + cur->right->sum;
    }
    int sumRange(Node* cur, int i, int j) {
        if (cur->start == i && cur->end == j) {
            return cur->sum;
        }
        int mid = (cur->start + cur->end) / 2;
        if (j <= mid) {
            return sumRange(cur->left, i, j);
        } else if (i >= mid + 1) {
            return sumRange(cur->right, i, j);
        } else {
            return sumRange(cur->left, i, mid) + sumRange(cur->right, mid + 1, j);
        }
    }
};
*/

// Partition the vector into several pieces.
class NumArray {
    struct Bucket {
        int sum;
        vector<int> ele;
    };
    int _bucketNum;
    int _bucketSize;
    vector<Bucket> _bv;
public:
    NumArray(vector<int> nums) {
        int n = nums.size();
        if (n != 0) {
            _bucketNum = (int)sqrt(2 * n);
        	_bucketSize = n % _bucketNum == 0 ? n / _bucketNum : n /_bucketNum + 1;
        	for (int i = 0; i < _bucketNum; ++i) {
          		Bucket *b = new Bucket;
            	int sum = 0;
            	int temp = i * _bucketSize;
            	for (int j = 0; j < _bucketSize &&  temp + j < n; ++j) {
                	sum += nums[temp + j];
                	b->ele.push_back(nums[temp + j]);
            	}
            	b->sum = sum;
            	_bv.push_back(*b);
        	}
        }
    }
    
    void update(int i, int val) {
        int j = i % _bucketSize;
        i = i / _bucketSize;
        _bv[i].sum += val - _bv[i].ele[j];
        _bv[i].ele[j] = val;
    }
    
    int sumRange(int i, int j) {
        int si = i / _bucketSize;
        int sj = i % _bucketSize;
        int ei = j / _bucketSize;
        int ej = j % _bucketSize;
        int sum = 0;
        if (si == ei) {
            for (int p = sj; p <= ej; ++p) {
            	sum += _bv[si].ele[p];
            }
            return sum;
        }
        for (int p = sj; p < _bucketSize; ++p) {
            sum += _bv[si].ele[p];
        }
        for (int p = si + 1; p < ei; ++p) {
            sum += _bv[p].sum;
        }
        for (int p = 0; p <= ej; ++p) {
            sum += _bv[ei].ele[p];
        }
        return sum;
    }
};
// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */