#include <bits/stdc++.h>
using namespace std;

// Single Number

// int main(){
//     int size;
//     cin >> size;
//     vector<int> nums(size);
//     int res = 0, n = nums.size();
//     for (int i = 0; i < n; i++) res = res^nums[i];
//     cout << res << '\n';
//     return 0;
// }

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0, n = nums.size();
        for (int i = 0; i < n; i++) res = res^nums[i];
        return res;
    }
};

int main(){
    Solution sol;
    int size;
    cin >> size;
    vector<int> nums(size);
    for (int i = 0; i < size; i++) cin >> nums[i];
    cout << sol.singleNumber(nums) << '\n';
    return 0;
}