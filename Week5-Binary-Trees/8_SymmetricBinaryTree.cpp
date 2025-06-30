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
    bool check(TreeNode* node1, TreeNode* node2){
        if (node1 == nullptr && node2 == nullptr) return true;
        else if ((node1 == nullptr || node2 == nullptr) && !(node1 == nullptr && node2 == nullptr)) return false;
        return node1->val == node2->val && check(node1->right, node2->left) && check(node1->left, node2->right);
    }
    bool isSymmetric(TreeNode* root) {
        return check(root->left, root->right);
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
    
    // Assuming a simple binary tree structure for demonstration
    for (int i = 0; i < n; i++) {
        if (2 * i + 1 < n) nodes[i]->left = nodes[2 * i + 1];
        if (2 * i + 2 < n) nodes[i]->right = nodes[2 * i + 2];
    }
    
    bool result = solution.isSymmetric(nodes[0]); // Start from the root node
    cout << (result ? "true" : "false") << endl; // Output whether the binary tree is symmetric
}