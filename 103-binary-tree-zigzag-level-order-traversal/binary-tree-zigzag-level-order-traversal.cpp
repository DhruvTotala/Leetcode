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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue <TreeNode*> q;
        
        if(root == NULL) return ans;
        q.push(root);
        bool rtl = false;
        while(q.size() > 0) {
            int len = q.size();
            vector <int> temp;
            for(int i = 0; i < len; i++) {
                TreeNode* curr = q.front();
                temp.push_back(curr -> val);
                q.pop();
                if(curr -> left != NULL) q.push(curr -> left);
                if(curr -> right != NULL) q.push(curr -> right);
            }
            if(rtl) reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            rtl = !rtl;
        }
        return ans;
    }
};