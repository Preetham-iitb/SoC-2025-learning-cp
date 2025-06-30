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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root){
            if (p->val > root->val && q->val > root->val) root = root->right;
            else if (p->val < root->val && q->val < root->val) root = root->left;
            else return root;
        }
        return nullptr;        
    }
};

int main() {
    // Example usage:
    Solution sol;
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    TreeNode* p = root->left; // Node with value 2
    TreeNode* q = root->left->right; // Node with value 4

    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);
    
    if (lca) {
        cout << "Lowest Common Ancestor: " << lca->val << endl; // Should print 2
    } else {
        cout << "No common ancestor found." << endl;
    }

    return 0;
}