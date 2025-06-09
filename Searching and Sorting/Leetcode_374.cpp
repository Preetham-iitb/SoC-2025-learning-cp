#include <bits/stdc++.h>
using namespace std;

// Guess Number Higher or Lower

int lifeisamess(int num) {
    int x = 0;
    if (num == 6) x = 0;
    else if (num < 6) x = 1;
    else x = -1;
    return x; 
}
class Solution {
public:
    int guessNumber(int n) {
        int left = 1;
        int right = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int result = lifeisamess(mid);
            if (result == 0) return mid;
            else if (result == -1) right = mid - 1;
            else left = mid + 1;
        }
        return -1;
        }
};

int main() {
    Solution sol;
    int n;
    cin >> n;
    cout << sol.guessNumber(n) << '\n';
    return 0;
}