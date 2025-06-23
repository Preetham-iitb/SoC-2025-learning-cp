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
    int climbStairs(int n) {
        int single = n%2, dub = n/2;
        long long count = 1;
        if(dub == 0) return 1;
        while(dub > 0){
            count+=nCr(single+dub, dub);
            single+=2;
            dub--;
        }
        return count;
    }
};

int main() {
    Solution solution;
    int n;
    cin >> n; // Input the number of steps
    int result = solution.climbStairs(n);
    cout << result << endl; // Output the number of distinct ways to climb the stairs
    return 0;
}