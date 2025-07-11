#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int clusters = 0, m = connections.size();
        if (m + 1 < n) return -1;
        vector<vector<int>> adj(n);
        for (const auto& conn : connections) {
            adj[conn[0]].push_back(conn[1]);
            adj[conn[1]].push_back(conn[0]);
        }
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++){
            if (!vis[i] && ++clusters)
                checkConn(i, adj, vis);
        }
        return clusters - 1;
    }
    
    void checkConn(int u, vector<vector<int>>& adj, vector<bool>& vis) {
        if (vis[u]) return;
        vis[u] = true;
        for (const int& v : adj[u]){
            if (!vis[v]) checkConn(v, adj, vis);
        }
    }
};

int main() {
    Solution sol;

    // Test case 1: 4 computers with connections [[0,1],[0,2],[1,2]]
    vector<vector<int>> connections1 = {{0, 1}, {0, 2}, {1, 2}};
    cout << "Test case 1: " << sol.makeConnected(4, connections1) << " operations needed" << endl;

    // Test case 2: 6 computers with connections [[0,1],[0,2],[0,3],[1,4]]
    vector<vector<int>> connections2 = {{0, 1}, {0, 2}, {0, 3}, {1, 4}};
    cout << "Test case 2: " << sol.makeConnected(6, connections2) << " operations needed" << endl;

    // Test case 3: Not enough connections
    vector<vector<int>> connections3 = {{0, 1}, {0, 2}};
    cout << "Test case 3: " << sol.makeConnected(5, connections3) << " operations needed" << endl;

    return 0;
}