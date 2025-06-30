#include <bits/stdc++.h>
using namespace std;

//  * Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* insert(vector<int>& nums, int left, int right){
        if (left > right) return nullptr;
        int mid = left + (right-left)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = insert(nums, left, mid-1);
        node->right = insert(nums, mid+1, right);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return insert(nums, 0, nums.size()-1);
    }
};

int main() {
    Solution solution;
    int n, val;
    cin >> n; // Input the number of elements in the sorted array
    vector<int> nums(n);
    
    for (int i = 0; i < n; i++) {
        cin >> nums[i]; // Input the value of each element
    }
    
    TreeNode* root = solution.sortedArrayToBST(nums); // Convert sorted array to BST
    // Output the BST or perform any operations as needed
    return 0;
}