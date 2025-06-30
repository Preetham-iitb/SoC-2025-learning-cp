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
    void postOrder(TreeNode* node, vector<int>& ans){
        if(node == nullptr) return;
        postOrder(node->left, ans);
        postOrder(node->right, ans);
        ans.push_back(node->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postOrder(root, ans);
        return ans;
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
    
    vector<int> result = solution.postorderTraversal(nodes[0]); // Start from the root node
    for (int val : result) {
        cout << val << " "; // Output the postorder traversal
    }
    cout << endl;

    return 0;
}