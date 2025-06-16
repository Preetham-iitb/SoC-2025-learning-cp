#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int& num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k)
                minHeap.pop();
        }

        return minHeap.top();
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    int result = solution.findKthLargest(nums, k);
    cout << result << endl; // Output: 5
    return 0;
}