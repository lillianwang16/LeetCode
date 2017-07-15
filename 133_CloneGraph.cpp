/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

/*
// BFS solution.
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<int, UndirectedGraphNode *> m;
        queue<UndirectedGraphNode *> q;
        if (node == NULL)   return NULL;
        UndirectedGraphNode* res = new UndirectedGraphNode(node->label);
        m[node->label] = res;
        q.push(node);
        while (!q.empty()) {
            UndirectedGraphNode* cur = q.front();
            q.pop(); 
            UndirectedGraphNode* clone = m[cur->label];
            for (UndirectedGraphNode* neigh: cur->neighbors) {
                 UndirectedGraphNode* n_clone;
                if (m.find(neigh->label) == m.end()) {
                    n_clone = new UndirectedGraphNode(neigh->label);
                    m[neigh->label] = n_clone;
                    q.push(neigh); // Only push unvisited node to queue.
                } else {
                    n_clone = m[neigh->label];
                }
                clone->neighbors.push_back(n_clone);
            }
        }
        return res; 
    }
};
*/
// DFS solution.
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL)   return NULL;
        if (m.find(node->label) != m.end())     return m[node->label];
        UndirectedGraphNode *clone = new UndirectedGraphNode(node->label);
        m[node->label] = clone;
        for (UndirectedGraphNode *n : node->neighbors) {
            clone->neighbors.push_back(cloneGraph(n));
        }
        m[node->label] = clone;
        return clone;
    }
        
private:
    unordered_map<int, UndirectedGraphNode *> m;
};