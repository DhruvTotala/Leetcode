class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int MOD = 12345;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> result(m, vector <int> (n));

        long long suff = 1;
        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                result[i][j] = suff;
                suff = (suff * grid[i][j]) % MOD;
            }
        }

        long long pref = 1;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                result[i][j] = (result[i][j] * pref) % MOD;
                pref = (pref * grid[i][j]) % MOD;
            }
        }
        return result;
    }
};