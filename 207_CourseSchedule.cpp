/*
//DFS.
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> s(numCourses, vector<int>(0));
        for (pair<int, int> p : prerequisites) {
            s[p.first].push_back(p.second);
        }
        for (int i = 0; i < numCourses; ++i) {
            vector<bool> visited(numCourses);
            visited[i] = true;
            if (graphSearch(s, visited, i)) {
                return false;
            }
            visited[i] = false;
        }
        return true;
    }
private: 
    bool graphSearch(vector<vector<int>>& s, vector<bool>& visited, int i) {
        if (s[i].size() == 0) {
            return false;
        }
        bool flag = false;
        for (int j : s[i]) {
            if (visited[j]) {
                return true;
            } else {
                visited[j] = true;
                flag = flag || graphSearch(s, visited, j);
                visited[j] = false;
            }
        }
        s[i].clear();
        return flag;
    }
};
*/


// BFS. Graph with no 0-indegree nodes should have a circle. 
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> s(numCourses, vector<int>(0));
        vector<int> indegree(numCourses);
        for (pair<int, int> p : prerequisites) {
            s[p.first].push_back(p.second);
            ++indegree[p.second];
        }
        for (int i = 0; i < numCourses; ++i) {
            int j = 0;
            for (; j < numCourses; ++j) {
                if (indegree[j] == 0) {
                    break;
                }
            }
            if (j == numCourses) {
                return false;
            }
            indegree[j] = -1;
            for (int neighbor : s[j]) {
                --indegree[neighbor];
            }
        }
        return true;
    }
};
