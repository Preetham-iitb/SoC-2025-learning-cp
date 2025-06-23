#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        if (sum % 2 != 0)
            return false;
        bitset<10001> bit(1);
        for (int i = 0; i < nums.size(); i++) {
            bit |= bit << nums[i];
            if (bit[sum / 2])
                return true;
        }
        return bit[sum / 2];
    }
};

int main() {
    Solution solution;
    int n;
    cin >> n; // Input the number of elements in the array
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i]; // Input the elements of the array
    }
    bool result = solution.canPartition(nums);
    cout << (result ? "true" : "false") << endl; // Output whether the array can be partitioned into two equal subsets
    return 0;
}