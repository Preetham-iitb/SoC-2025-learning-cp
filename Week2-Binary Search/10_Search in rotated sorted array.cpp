#include <bits/stdc++.h>
using namespace std;

// Search in Rotated Sorted Array

class Solution {
public:
    int search(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int mid = (left + right)/2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] >= nums[left]){
                if (nums[left] <= target && target <= nums[mid]) right = mid - 1;
                else left = mid + 1;
            }
            else{
                if (nums[mid] <= target && target <= nums[right]) left = mid + 1;
                else right = mid - 1;
            }
        }
        return -1;
    }
};

int main(){
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    Solution sol;
    int result = sol.search(nums, target);
    cout << result << endl; // Output: 4
    return 0;
}