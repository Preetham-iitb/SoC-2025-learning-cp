#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int x, vector<int>& color, vector<vector<int>>& graph, int y){
        if(y == -1) color[x] = 0;
        else color[x] = !color[y];

        for(auto i: graph[x]){
            if(color[i] == color[x]) return false;
            else if(color[i] == -1){
                if(!dfs(i,color,graph,x))
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size());
        for(int i = 0; i < graph.size(); i++){
            color[i] = -1;
        }
        for(int i = 0; i < graph.size(); i++){
            if(color[i]==-1){
                if(!dfs(i,color,graph,-1))
                return false;
            }
        }
        return true;
    }
};