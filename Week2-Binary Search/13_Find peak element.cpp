#include <bits/stdc++.h>
using namespace std;

// Find Peak Element in an Array

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[nums.size()-1] > nums[nums.size()-2]) return nums.size()-1;
        
        for (int i = 1; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                return i;
            }
        }
        return 0;
    }
};

int main() {
    Solution sol;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << sol.findPeakElement(nums) << '\n';
    return 0;
}