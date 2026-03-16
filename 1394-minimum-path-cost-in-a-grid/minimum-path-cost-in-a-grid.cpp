class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
            dp[m - 1][i] = grid[m - 1][i];

        for (int i = m - 2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = INT_MAX;
                for (int k = 0; k < n; k++) {
                    int move = moveCost[grid[i][j]][k];
                    dp[i][j] = min(dp[i][j], grid[i][j] + move + dp[i + 1][k]);
                }
            }
        }

        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
            ans = min(ans, dp[0][i]);

        return ans;
    }
};