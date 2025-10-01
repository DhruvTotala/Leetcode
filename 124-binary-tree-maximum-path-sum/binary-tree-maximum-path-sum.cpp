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
    int ans = INT_MIN;
    int dfs(TreeNode* root) {
        if(root == NULL) return 0;
        int l_s = dfs(root -> left);
        if(l_s < 0) l_s = 0;
        int r_s = dfs(root -> right);
        if(r_s < 0) r_s = 0;
        ans = max(ans, l_s + r_s + root -> val);

        return max(r_s, l_s) + root -> val;
    }
    int maxPathSum(TreeNode* root) {
        if(root == NULL) return 0;
        dfs(root);
        return ans;
    }
};