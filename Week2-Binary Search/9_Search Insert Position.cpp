#include <bits/stdc++.h>
using namespace std;

// Search Insert Position

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        int mid;
        if (target > nums[right-1]) return right;
        while(left <= right){
            mid = left + (right - left)/2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return left;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;
    cout << sol.searchInsert(nums, target) << endl; // Output: 2
    target = 2;
    cout << sol.searchInsert(nums, target) << endl; // Output: 1
    target = 7;
    cout << sol.searchInsert(nums, target) << endl; // Output: 4
    target = 0;
    cout << sol.searchInsert(nums, target) << endl; // Output: 0
    return 0;
}