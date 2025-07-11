#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<int> dir={-1,0,1,0,-1};
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int,int>> q;
        int fresh = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2) q.push({i,j});
                if(grid[i][j] == 1) fresh++;
            }
        }
        int ans = -1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                pair<int,int> p = q.front();
                q.pop();
                for(int i = 0; i < 4; i++){
                    int r = p.first + dir[i];
                    int c = p.second + dir[i+1];
                    if(r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1){
                        grid[r][c] = 2;
                        q.push({r,c});
                        fresh--;
                    }
                }
            }
            ans++;
        }
        if(fresh > 0) return -1;
        if(ans==-1) return 0;
        return ans;
    }
};

int main(){
    Solution sol;
    
    // Test case 1: 3x3 grid with some rotten oranges
    vector<vector<int>> grid1 = {
        {2, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };
    cout << "Test case 1: " << sol.orangesRotting(grid1) << " minutes" << endl;
    
    // Test case 2: All oranges are fresh
    vector<vector<int>> grid2 = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    };
    cout << "Test case 2: " << sol.orangesRotting(grid2) << " minutes" << endl;
    
    // Test case 3: All oranges are rotten
    vector<vector<int>> grid3 = {
        {2, 2, 2},
        {2, 2, 2},
        {2, 2, 2}
    };
    cout << "Test case 3: " << sol.orangesRotting(grid3) << " minutes" << endl;

    return 0;
}