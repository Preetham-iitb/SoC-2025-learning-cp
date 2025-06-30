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
    int subTreeDepth(TreeNode* node){
        if (node == nullptr) return 0;
        int left = 1 + subTreeDepth(node->left);
        int right = 1 + subTreeDepth(node->right);
        return max(left, right);
    }
    int maxDepth(TreeNode* root) {
        return subTreeDepth(root);
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
    
    int result = solution.maxDepth(nodes[0]); // Start from the root node
    cout << result << endl; // Output the maximum depth of the binary tree
}