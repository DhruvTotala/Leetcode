/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* root, int idx) {
        if(root == NULL) return 0;
        idx = idx * 2 + root -> val;
        if(root -> left == root -> right) return idx;
        return dfs(root -> left, idx) + dfs(root -> right, idx);
    }
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
};