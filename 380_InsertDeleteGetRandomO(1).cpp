/*
//Hash with randomed iterator.
class RandomizedSet {
public:
    // Initialize your data structure here. 
    RandomizedSet() {
        _N = 0;
    }
    
    // Inserts a value to the set. Returns true if the set did not already contain the specified element. 
    bool insert(int val) {
        if (_m.find(val) == _m.end()) {
            _m.insert(val);
            ++_N;
            return true;
        }
        return false;
    }
    
    // Removes a value from the set. Returns true if the set contained the specified element. 
    bool remove(int val) {
        if (_m.find(val) != _m.end()) {
            _m.erase(val);
            --_N;
            return true;
        }
        return false;
    }
    
    // Get a random element from the set.
    int getRandom() {
        if (_N == 0) return 0;
        int n = rand() % _N;
        unordered_set<int> :: iterator it = _m.begin();
        auto newit = next(it, n);
        return *newit;
    }
private:
    unordered_set<int> _m;
    int _N;
};
*/


//Hash with vector.
class RandomizedSet {
public:
    // Initialize your data structure here. 
    RandomizedSet() {
    }
    
    // Inserts a value to the set. Returns true if the set did not already contain the specified element. 
    bool insert(int val) {
        if (_locs.find(val) == _locs.end()) {
            _locs[val] = _nums.size();
            _nums.push_back(val);
            return true;
        }
        return false;
    }
    
    // Removes a value from the set. Returns true if the set contained the specified element. 
    bool remove(int val) {
        if (_locs.find(val) != _locs.end()) {
            int loc = _locs[val];
            _locs.erase(val);
            if (loc != _nums.size() - 1) {
                _locs[_nums[_nums.size() - 1]] = loc;
                swap(_nums[loc], _nums[_nums.size() - 1]);
            }
            _nums.pop_back();
            return true;
        }
        return false;
    }
    
    // Get a random element from the set.
    int getRandom() {
        if (_nums.empty()) return 0;
        return _nums[rand() % _nums.size()];
    }
private:
    unordered_map<int, int> _locs;
    vector<int> _nums;
};
/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */