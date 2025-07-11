#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void countTime(int node, int time, vector<vector<pair<int, int>>>& adj, vector<int>& dist) {
        if (time >= dist[node]) return;
        dist[node] = time;

        for (auto& it : adj[node]) {
            int neighbour = it.first;
            int weight = it.second;
            countTime(neighbour, time + weight, adj, dist);
        }
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& it : times) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v, w});
        }
        vector<int> dist(n + 1, INT_MAX);
        countTime(k, 0, adj, dist);
        int totalTime = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            totalTime = max(totalTime, dist[i]);
        }
        return totalTime;
    }
};

int main() {
    Solution sol;

    // Test case 1: 3 nodes with times [[2,1,1],[2,3,1],[3,4,1]]
    vector<vector<int>> times1 = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    cout << "Test case 1: " << sol.networkDelayTime(times1, 4, 2) << " time units" << endl;

    // Test case 2: No reachable nodes
    vector<vector<int>> times2 = {{1, 2, 1}};
    cout << "Test case 2: " << sol.networkDelayTime(times2, 2, 1) << " time units" << endl;

    // Test case 3: All nodes reachable
    vector<vector<int>> times3 = {{1, 2, 5}, {2, 3, 10}, {1, 3, 15}};
    cout << "Test case 3: " << sol.networkDelayTime(times3, 3, 1) << " time units" << endl;

    return 0;
}