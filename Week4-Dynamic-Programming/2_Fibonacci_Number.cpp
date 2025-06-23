#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fib(int n) {
        int prev2 = 0, prev = 1;
        if(n == 0) return prev2;
        else if(n == 1) return prev;
        for (int i = 1; i < n; i++){
            int curri = prev + prev2;
            prev2 = prev;
            prev = curri;
        }
        return prev;
    }
};

int main() {
    Solution solution;
    int n;
    cin >> n; // Input the Fibonacci number index
    int result = solution.fib(n);
    cout << result << endl; // Output the nth Fibonacci number
    return 0;
}