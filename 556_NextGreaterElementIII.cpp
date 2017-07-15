class Solution {
public:
    int nextGreaterElement(int n) {
        if (n == INT_MAX)   return -1;
        multiset<int> store;
        int last = n % 10, cur;
        store.insert(last);
        bool flag = false;
        n /= 10;
        while (n > 0) {
            cur = n % 10;
            n /= 10;
            if (cur < last) {
                flag = true;
                break;
            }
            last = cur;
            store.insert(cur);
        }
        if (!flag)  return -1;
        auto it = store.upper_bound(cur);
        store.insert(cur);
        cur = *it;
        store.erase(it);
        n = n * 10 + cur;
        for (it = store.begin(); it != store.end(); ++it) {
            if (n > INT_MAX / 10 || (n == INT_MAX / 10 && *it > INT_MAX % 10)) {
                return -1;
            }
            n = n * 10 + *it;
        }
        return n;
    }
};