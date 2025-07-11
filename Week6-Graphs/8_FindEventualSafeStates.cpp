#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool DFSisCycle(int s, vector<vector<int>>& graph, vector<bool>& isSafe, vector<bool>& vis, vector<bool>& DFS_vis) {
        vis[s] = true;
        DFS_vis[s] = true;
        bool flag = false;

        for (int x : graph[s]) {
            if (DFS_vis[x]) flag = true;
            else if (!vis[x]) flag = flag || DFSisCycle(x, graph, isSafe, vis, DFS_vis);
            else if (!isSafe[x]) flag = true;
        }

        DFS_vis[s] = false;
        if (!flag) isSafe[s] = true;
        return flag;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<bool> vis(V, false), DFS_vis(V, false), isSafe(V, false);
        vector<int> ans;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) DFSisCycle(i, graph, isSafe, vis, DFS_vis);
        }

        for (int i = 0; i < V; i++) {
            if (isSafe[i]) ans.push_back(i);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Test case 1: Graph with eventual safe nodes
    vector<vector<int>> graph1 = {
        {1, 2}, 
        {2, 3}, 
        {5}, 
        {0}, 
        {5}, 
        {}, 
        {}
    };
    vector<int> result1 = sol.eventualSafeNodes(graph1);
    cout << "Test case 1: ";
    for (int node : result1) {
        cout << node << " ";
    }
    cout << endl;

    // Test case 2: Graph with no safe nodes
    vector<vector<int>> graph2 = {
        {1, 2, 3, 4}, 
        {0, 4}, 
        {0, 4}, 
        {0, 4}, 
        {}
    };
    vector<int> result2 = sol.eventualSafeNodes(graph2);
    cout << "Test case 2: ";
    for (int node : result2) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}