#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q(stones.begin(), stones.end());
        while (q.size() > 1) {
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            if (a != b) {
                int diff = abs(a - b);
                q.push(diff);
            }
        }
        return q.size() == 1 ? q.top() : 0;
    }
};

int main() {
    Solution solution;
    vector<int> stones = {2, 7, 4, 1, 8, 1};
    int result = solution.lastStoneWeight(stones);
    cout << result << endl; // Output: 1
    return 0;
}