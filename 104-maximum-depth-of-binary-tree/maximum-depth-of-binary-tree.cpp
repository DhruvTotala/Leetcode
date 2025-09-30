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
    int bfs(TreeNode* root) {
        if(root == NULL) return 0;

        int left_h = bfs(root -> left);
        int right_h = bfs(root -> right);

        return max(left_h, right_h) + 1;
    }
    
    int maxDepth(TreeNode* root) {
        return bfs(root);
    }
};