#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int checkMax(vector<int>& nums){
        int prevRob = 0;
        int maxRob = 0;
        for (int i = 0; i < nums.size(); i++) {
            int temp = max(maxRob, prevRob + nums[i]);
            prevRob = maxRob;
            maxRob = temp;
        }
        return maxRob;
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> subarr1(nums.begin(), nums.end()-1);
        vector<int> subarr2(nums.begin()+1, nums.end());
        return max(checkMax(subarr1), checkMax(subarr2));        
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