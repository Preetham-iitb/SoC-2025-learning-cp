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
    void pushElement(TreeNode*& root,vector<int>& v){
         if(!root) return;
         pushElement(root->left,v);
         v.push_back(root->val);
         pushElement(root->right,v);
     }

    int getMinimumDifference(TreeNode* root) {
         vector<int>v;
         pushElement(root,v);
         int minDiff = INT_MAX;
         for(int i=0; i<v.size()-1; i++) minDiff = min(minDiff,v[i+1] - v[i]);
         return minDiff;
    }
};

int main() {
    // Example usage:
    Solution sol;
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    int minDiff = sol.getMinimumDifference(root);
    cout << "Minimum Absolute Difference in BST: " << minDiff << endl; // Should print 1

    return 0;
}