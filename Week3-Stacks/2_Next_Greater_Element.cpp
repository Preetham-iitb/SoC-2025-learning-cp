#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> ans;
        for (int i = 0; i < n1; i++){
            pair<int, int> x;
            x.first = nums1[i];
            x.second = nums1[i];
            for (int j = nums2.size() - 1; j >= 0; j--){
                if(nums2[j] == x.first) break;
                if (nums2[j] > x.first) x.second = nums2[j];
            }
            if(x.second == x.first) x.second = -1;
            ans.push_back(x.second);
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> result = solution.nextGreaterElement(nums1, nums2);
    
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}