class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector <int> sum_x(n, 0);
        vector <int> sum_y(n, 0);
        int ans = 0;
        for(int i = 0; i < m; i++) {
            int x = 0, y = 0;
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 'X') x++;
                else if(grid[i][j] == 'Y') y++;
                sum_x[j] += x;
                sum_y[j] += y;
                if(sum_x[j] > 0 && sum_x[j] == sum_y[j]) ans++;
            }
        }
        return ans;
    }
};