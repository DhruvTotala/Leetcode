class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector <int> ans;

        map <int, vector<int>> mp;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                mp[i + j].push_back(mat[i][j]);
            }
        }

        for(auto &p : mp) {
            if(p.first % 2 == 0) {
                for(int i = p.second.size() - 1; i >= 0; i--) {
                    ans.push_back(p.second[i]);
                }
            } else {
                for(int x : p.second) {
                    ans.push_back(x);
                }
            }
        }
    return ans;
    }
};