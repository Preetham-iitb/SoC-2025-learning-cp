#include <bits/stdc++.h>
using namespace std;

// Search element in a sorted array

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int res = 0, n = nums.size();
        for (int i = 0; i < n; i++) res = res^nums[i];
        return res;
    }
};

int main() {
    Solution sol;
    int size;
    cin >> size;
    vector<int> nums(size);
    for (int i = 0; i < size; i++) cin >> nums[i];
    cout << sol.singleNonDuplicate(nums) << '\n';
    return 0;
}