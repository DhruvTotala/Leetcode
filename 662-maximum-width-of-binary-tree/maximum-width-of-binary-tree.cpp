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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        long long ans = 0;
        queue<pair<TreeNode*, long long>> q;  // pair of node and its index
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            long long first = q.front().second;  // minimum index at this level
            long long last = q.back().second;    // maximum index at this level
            ans = max(ans, last - first + 1);

            for (int i = 0; i < size; i++) {
                auto [node, idx] = q.front();
                q.pop();

                // To prevent overflow, use relative index
                long long rel_idx = idx - first;

                if (node->left)
                    q.push({node->left, 2 * rel_idx + 1});
                if (node->right)
                    q.push({node->right, 2 * rel_idx + 2});
            }
        }

        return (int)ans;
    }
};
