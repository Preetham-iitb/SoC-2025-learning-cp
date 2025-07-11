#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void visited(vector<vector<int>>& cities, int j){
        cities[j][j] = 0;
        int len = cities.size();
        for (int k = 0; k < len; k++){
            if (cities[j][k] == 1){
                cities[j][k] = 0;
                cities[k][j] = 0;
                visited(cities, k);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int len = isConnected.size();
        int ans = 0;
        for(int i = 0; i < len; i++){
            if (isConnected[i][i] == 1){
                visited(isConnected, i);
                ans++;
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    
    // Test case 1: 3 cities with connections [[1,1,0],[1,1,0],[0,0,1]]
    // Expected output: 2 provinces
    vector<vector<int>> isConnected1 = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };
    cout << "Test case 1: " << sol.findCircleNum(isConnected1) << " provinces" << endl;
    
    // Test case 2: 3 cities with connections [[1,0,0],[0,1,0],[0,0,1]]
    // Expected output: 3 provinces
    vector<vector<int>> isConnected2 = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };
    cout << "Test case 2: " << sol.findCircleNum(isConnected2) << " provinces" << endl;
    
    // Test case 3: 4 cities with more complex connections
    // Expected output: 1 province
    vector<vector<int>> isConnected3 = {
        {1, 1, 0, 1},
        {1, 1, 1, 0},
        {0, 1, 1, 1},
        {1, 0, 1, 1}
    };
    cout << "Test case 3: " << sol.findCircleNum(isConnected3) << " provinces" << endl;
    
    return 0;
}