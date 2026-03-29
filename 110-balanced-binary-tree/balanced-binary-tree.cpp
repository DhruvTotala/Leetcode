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
    int checkHeight(TreeNode* root) {
        if(!root) return 0;
        int leftH = checkHeight(root -> left);
        if(leftH == -1) return -1;
        int rightH = checkHeight(root -> right);
        if(rightH == -1) return -1;
        if(abs(leftH - rightH) > 1) return -1;
        return max(leftH, rightH) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
};