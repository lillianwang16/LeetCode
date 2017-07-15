/*
//BFS.
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> s(numCourses);
        vector<int> indegree(numCourses);
        vector<int> ans(numCourses);
        for (int i = 0; i < prerequisites.size(); ++i) {
            s[prerequisites[i].first].push_back(prerequisites[i].second);
            ++indegree[prerequisites[i].second];
        }
        for (int i = 0; i < numCourses; ++i) {
            int j = 0;
            for (; j < numCourses; ++j) {
                if (indegree[j] == 0) {
                    break;
                }
            }
            if (j == numCourses) {
                return vector<int>();
            }
            indegree[j] = -1;
            ans[numCourses - i - 1] = j;
            for (int neigh : s[j]) {
                --indegree[neigh];
            }
        }
        return ans;
    }
};
*/

//DFS.
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> s(numCourses);
        vector<bool> visited(numCourses);
        vector<bool> onpath(numCourses);
        vector<int> ans;
        for (int i = 0; i < prerequisites.size(); ++i) {
            s[prerequisites[i].first].push_back(prerequisites[i].second);
        }      
        for (int i = 0; i < numCourses; ++i) {
            if (!DFS(s, ans, onpath, visited, i)) {
                return vector<int>();
            }
        }
        return ans;
    }
private:
    bool DFS(vector<vector<int>>& s,vector<int>& ans, vector<bool>& onpath, vector<bool>& visited, int i) {
        if (visited[i]) {
            return true;
        }
        onpath[i] = true;
        for (int neigh : s[i]) {
            if (onpath[neigh]) {
                return false;
            } else if (!DFS(s, ans, onpath, visited, neigh)) {
                    return false;
            }
        }
        visited[i] = true;
        onpath[i] = false;
        ans.push_back(i);
        return true;
    }
};