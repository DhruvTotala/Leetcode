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
    int height(TreeNode* root) {
        if(root == NULL) return 0;

        int left_h = height(root -> left);
        int right_h = height(root -> right);
        return max(left_h, right_h) + 1;
    }

    bool dfs(TreeNode* root) {
        if(root == NULL) return true;

        int left_h = height(root -> left);
        int right_h = height(root -> right);

        if(abs(left_h - right_h) <= 1 && dfs(root -> left) == true && dfs(root -> right)) {
            return true;
        }
        return false;
    }
    
    bool isBalanced(TreeNode* root) {
        return dfs(root);
    }
};