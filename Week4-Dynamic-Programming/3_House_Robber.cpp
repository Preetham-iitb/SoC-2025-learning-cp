#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int prevRob = 0;
        int maxRob = 0;
        for (int i = 0; i < nums.size(); i++) {
            int temp = max(maxRob, prevRob + nums[i]);
            prevRob = maxRob;
            maxRob = temp;
        }
        return maxRob;        
    }
};

int main() {
    Solution solution;
    int n;
    cin >> n; // Input the number of houses
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i]; // Input the amount of money in each house
    }
    int result = solution.rob(nums);
    cout << result << endl; // Output the maximum amount of money that can be robbed
    return 0;
}