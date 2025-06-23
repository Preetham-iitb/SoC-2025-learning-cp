#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(vector<int>& nums, int target, int sum, int idx) {
        if (idx == nums.size()) {
            return target == sum ? 1 : 0;
        }
        int add = helper(nums, target, sum + nums[idx], idx + 1);
        int subtract = helper(nums, target, sum - nums[idx], idx + 1);
        return add + subtract;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return helper(nums, target, 0, 0);
    }
};

int main() {
    Solution solution;
    int n, target;
    cin >> n; // Input the number of elements in the array
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i]; // Input the elements of the array
    }
    cin >> target; // Input the target sum
    int result = solution.findTargetSumWays(nums, target);
    cout << result << endl; // Output the number of ways to achieve the target sum
    return 0;
}