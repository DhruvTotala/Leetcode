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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        // tc = O(N) log N ; log N cz of multiset
        // sc = O(N)

        queue<pair<TreeNode*, pair<int, int>>> q;
        map<int, map<int, multiset<int>>> mpp;

        if(root == NULL) return{};

        q.push({root, {0, 0}});

        while( !q.empty() ){

            auto p = q.front();
            q.pop();

            TreeNode* node = p.first;
            int v = p.second.first;
            int l = p.second.second;

            mpp[v][l].insert(node -> val);

            if(node -> left) q.push({node->left, {v - 1, l + 1}});
            if(node -> right) q.push({node->right, {v + 1, l + 1}});
            
        }

        vector<vector<int>> ans;

        for(auto it : mpp){
            vector<int> col;

            for(auto x : it.second){
                col.insert(col.end(), x.second.begin(), x.second.end());
                // col.insert(where you want to insert, range)
            }
            ans.push_back(col);
        }

        return ans;
    }
};