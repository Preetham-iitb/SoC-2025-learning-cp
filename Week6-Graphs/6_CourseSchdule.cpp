#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0]; 
            int v = prerequisites[i][1];
            graph[v].push_back(u); 
        }

        vector<bool> visited(numCourses, false);
        vector<bool> path(numCourses, false);

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (!dfs(graph, visited, path, i)) {
                    return false;
                }
            }
        }
        return true;
    }

    bool dfs(vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &path, int course) {
        if (path[course]) return false;
        if (visited[course]) return true; 
        path[course] = true;

        for (int i = 0; i < graph[course].size(); i++) {
            int nei = graph[course][i];
            if (!dfs(graph, visited, path, nei)) return false;
        }

        path[course] = false;
        visited[course] = true;

        return true;
    }
};

int main() {
    Solution sol;

    // Test case 1: 2 courses with prerequisites [[1,0]]
    vector<vector<int>> prerequisites1 = {{1, 0}};
    cout << "Test case 1: " << (sol.canFinish(2, prerequisites1) ? "Can finish" : "Cannot finish") << endl;

    // Test case 2: 2 courses with prerequisites [[1,0],[0,1]]
    vector<vector<int>> prerequisites2 = {{1, 0}, {0, 1}};
    cout << "Test case 2: " << (sol.canFinish(2, prerequisites2) ? "Can finish" : "Cannot finish") << endl;

    // Test case 3: 4 courses with prerequisites [[1,0],[2,1],[3,2]]
    vector<vector<int>> prerequisites3 = {{1, 0}, {2, 1}, {3, 2}};
    cout << "Test case 3: " << (sol.canFinish(4, prerequisites3) ? "Can finish" : "Cannot finish") << endl;

    return 0;
}