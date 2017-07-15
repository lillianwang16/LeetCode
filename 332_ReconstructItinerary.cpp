class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, multiset<string>> m;
        for (pair<string, string> t : tickets) {
            m[t.first].insert(t.second);
        }
        vector<string> res;
        find(res, "JFK", m);
        reverse(res.begin(), res.end());
        return res;
    }
private:
    void find(vector<string>& res, string cur, unordered_map<string, multiset<string>>& m) {
        while (!m[cur].empty()) {
            string next = *m[cur].begin();
            m[cur].erase(m[cur].begin());
            find(res, next, m);
        }
        res.push_back(cur);
    }
};
/*
class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, multiset<string>> m;
        for (pair<string, string> t : tickets) {
            if (m.find(t.first) == m.end()) {
                multiset<string> to;
                m[t.first] = to;
            }
            m[t.first].insert(t.second);
        }
        vector<string> res;
        res.push_back("JFK");
        find(res, "JFK", m);
        return res;
    }
private:
    bool flag = false;
    void find(vector<string>& res, string cur, unordered_map<string, multiset<string>>& m) {
        if (empty(m)) {
            flag = true;
            return;
        }
        cout << cur << " ";
        if (m.find(cur) != m.end()) {
            vector<string>  temp;
            for (string next : m[cur]) { 
                temp.push_back(next);
            }
            for (int i = 0; i < temp.size(); ++i) {
                string next = temp[i];
                cout << next << " ";
                res.push_back(next);
                m[cur].erase(m[cur].find(next));
                temp.erase(temp.begin() + i);
                find(res, next, m);
                if (flag)   return;
                m[cur].insert(next);
                temp.insert(temp.begin() + i, next);
                res.pop_back();       
            }
        }      
    }
    bool empty(unordered_map<string, multiset<string>>& m) {
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (!(it->second).empty()) {
                return false;
            }
        }
        return true;
    }
};
*/