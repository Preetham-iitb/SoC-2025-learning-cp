#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long nCr(int n, int r) {
        if (r > n - r) r = n - r;
        long long res = 1;
        for (int i = 0; i < r; ++i) {
            res *= (n - i);
            res /= (i + 1);
        }
        return res;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        for(int n = 1; n < numRows; n++){
            vector<int> vec;
            for(int r = 0; r <= n; r++){
                vec.push_back(nCr(n,r));
            }
            ans.push_back(vec);
        }
        return ans;
    }
};

int main() {
    Solution solution;
    int numRows;
    cin >> numRows; // Input the number of rows in Pascal's Triangle
    vector<vector<int>> result = solution.generate(numRows);
    
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " "; // Output each value in the row
        }
        cout << endl; // New line after each row
    }
    
    return 0;
}