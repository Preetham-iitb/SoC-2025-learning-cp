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
    TreeNode* findMin(TreeNode* node) {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        if (root->val == key){
            if (!root->left && !root->right) return nullptr;
            else if (!root->left) return root->right;
            else if (!root->right) return root->left;
            else{
                TreeNode* succ = findMin(root->right);
                root->val = succ->val;
                root->right = deleteNode(root->right, succ->val);
            }
        }
        else if (root->val > key) root->left = deleteNode(root->left, key);
        else if (root->val < key) root->right = deleteNode(root->right, key);
        return root;
    }
};

int main() {
    // Example usage:
    Solution sol;
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    
    int keyToDelete = 3;
    TreeNode* updatedRoot = sol.deleteNode(root, keyToDelete);

    // Add code to print or verify the updated tree if needed.
    
    return 0;
}