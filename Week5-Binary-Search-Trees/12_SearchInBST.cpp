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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr) return nullptr;
        else if (root->val == val) return root;
        else if (root->val > val) return searchBST(root->left, val);
        else return searchBST(root->right, val);
    }
};

int main() {
    Solution solution;
    int n, val;
    cin >> n; // Input the number of nodes in the tree
    vector<TreeNode*> nodes(n);
    
    for (int i = 0; i < n; i++) {
        cin >> val; // Input the value of the node
        nodes[i] = new TreeNode(val);
    }
    
    // Assuming a simple binary search tree structure for demonstration
    for (int i = 0; i < n; i++) {
        if (2 * i + 1 < n) nodes[i]->left = nodes[2 * i + 1];
        if (2 * i + 2 < n) nodes[i]->right = nodes[2 * i + 2];
    }
    
    int searchVal;
    cin >> searchVal; // Input the value to search in the BST
    TreeNode* result = solution.searchBST(nodes[0], searchVal); // Start from the root node
    
    if (result) {
        cout << "Found: " << result->val << endl; // Output the found value
    } else {
        cout << "Not Found" << endl; // Output if not found
    }
    
    return 0;
}