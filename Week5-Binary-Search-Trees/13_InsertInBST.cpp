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
    TreeNode* insertIntoBST(TreeNode*& root, int val) {
        if (root == nullptr) root = new TreeNode(val);
        else if (root->val > val) root->left = insertIntoBST(root->left, val);
        else if (root->val < val) root->right = insertIntoBST(root->right, val);
        return root;
    }
};

int main() {
    Solution solution;
    int n, val;
    cin >> n; // Input the number of nodes in the tree
    TreeNode* root = nullptr;

    for (int i = 0; i < n; i++) {
        cin >> val; // Input the value of the node
        solution.insertIntoBST(root, val);
    }

    // Output the BST or perform any operations as needed
    // For demonstration, we can print the inorder traversal of the BST
    function<void(TreeNode*)> inorder = [&](TreeNode* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->val << " ";
        inorder(node->right);
    };

    inorder(root);
    cout << endl;

    return 0;
}