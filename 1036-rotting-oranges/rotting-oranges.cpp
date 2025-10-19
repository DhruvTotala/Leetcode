class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair <int, int>> q;
        int fresh = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) q.push({i, j});
                else if(grid[i][j] == 1) fresh++;
            }
        }

        if(fresh == 0) return 0;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] ={0, 1, 0, -1};
        int minutes = -1;
        while(!q.empty()) {
            int size = q.size();
            minutes++;
            for(int i = 0; i < size; i++) {
            auto [row, col] = q.front();
            q.pop();
            for(int k = 0; k < 4; k++) {
                int nrow = row + delrow[k];
                int ncol = col + delcol[k];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1) {
                        grid[nrow][ncol] = 2; // rot it
                        fresh--;          // one less fresh orange
                        q.push({nrow, ncol}); // add to queue for next minute
                    }
            }
        }
        }
        return (fresh == 0) ? minutes : -1;
    }
};