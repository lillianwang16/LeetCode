// Remove leaves each time.
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (n == 1) return vector<int>{0};
        vector<unordered_set<int>> m(n);
        for (pair<int, int> edge : edges) {
            m[edge.first].insert(edge.second);
            m[edge.second].insert(edge.first);
        }
        vector<int> leaves;
        for (int i = 0; i < n; ++i) {
            if (m[i].size() == 1) {
                leaves.push_back(i);
            }
        }
        while (n > 2) {
            n -= leaves.size();
            vector<int> newLeaves;
            for (int i : leaves) {
                int j = *m[i].begin();
                m[j].erase(i);
                if (m[j].size() == 1) {
                    newLeaves.push_back(j);
                }            
            }
            leaves = newLeaves;
        }
        return leaves;
    }
};