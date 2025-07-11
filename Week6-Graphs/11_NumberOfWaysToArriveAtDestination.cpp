#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
       int M=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int,int >>> adj;
        for(auto &road :roads){
            int u = road[0];
            int v = road[1];
            int time = road[2];

            adj[u].push_back({v,time});
            adj[v].push_back({u,time});
        }

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        vector<long long>ans(n,LONG_MAX);
        vector<int>pathCount(n,0);
        ans[0] = 0;
        pathCount[0] = 1;
        pq.push({0,0});
        while(!pq.empty()){
            long long currTime = pq.top().first;
            int currNode = pq.top().second;

            pq.pop();

            for(auto&vec : adj[currNode]){
                int ngbr = vec.first;
                long long roadTime = vec.second;

                if(currTime + roadTime < ans[ngbr]){
                    ans[ngbr] = currTime+roadTime;
                    pq.push({ans[ngbr],ngbr});
                    pathCount[ngbr] = pathCount[currNode];
                }
                else if(currTime + roadTime == ans[ngbr]){
                    pathCount[ngbr] = (pathCount[ngbr] + pathCount[currNode])%M;
                }
            }
        }
        return pathCount[n-1];
    }
};

int main() {
    Solution sol;

    // Test case 1: 5 cities with roads [[0,1,2],[0,2,4],[1,2,1],[1,3,7],[2,3,3],[3,4,1]]
    vector<vector<int>> roads1 = {
        {0, 1, 2},
        {0, 2, 4},
        {1, 2, 1},
        {1, 3, 7},
        {2, 3, 3},
        {3, 4, 1}
    };
    cout << "Test case 1: " << sol.countPaths(5, roads1) << " ways to arrive at destination" << endl;

    // Test case 2: No paths available
    vector<vector<int>> roads2 = {};
    cout << "Test case 2: " << sol.countPaths(5, roads2) << " ways to arrive at destination" << endl;

    // Test case 3: Single path available
    vector<vector<int>> roads3 = {
        {0, 1, 10},
        {1, 4, 10},
        {0, 2, 5},
        {2, 3, 5},
        {3, 4, 5}
    };
    cout << "Test case 3: " << sol.countPaths(5, roads3) << " ways to arrive at destination" << endl;

    return 0;
}