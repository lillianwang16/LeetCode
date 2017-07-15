/* 
// Double Linked Node and hash table.
class LRUCache {
public:
    LRUCache(int capacity) {
        N = capacity;
        n = 0;
    }
    
    int get(int key) {
        if (m.find(key) == m.end()) {
            return -1;
        }
        ListNode* temp = m[key];
        if (n > 1 && temp != head) {
            if (temp == tail) {
                tail = tail->before;
                tail->next = NULL;
            } else {
                temp->before->next = temp->next;
                temp->next->before = temp->before;
            }
            temp->before = NULL;
            temp->next = head;
            head->before = temp;
            head = temp;
        }
        return head->val;
    }
    
    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            m[key]->val = value;
            get(key);
            return;
        }
        ListNode* newhead = new ListNode(key, value);
        ++n;
        if (n == 1) {
            tail = newhead;
            head = newhead;
            m[key] = head;
            return;
        }
        newhead->next = head;
        head->before = newhead;
        head = newhead;
        m[key] = head;
        while (n > N) {
            m.erase(tail->key);
            tail = tail->before;
            tail->next = NULL;
            --n;
        }
        return;
    }
private:
    struct ListNode {
        int val;
        int key;
        ListNode* next;
        ListNode* before;
        ListNode(int k, int v) :key(k), val(v), next(NULL), before(NULL) {}
    };
    unordered_map<int, ListNode*> m;
    int N = 0, n = 0;
    ListNode* head, *tail;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
 
 /*
 // Double linked nodes with extra head and tail node and hash table.