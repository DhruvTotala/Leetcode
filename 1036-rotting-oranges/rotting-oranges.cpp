class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        queue<pair<int, int>> q;
        int fresh = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) q.push({i, j});
                else if(grid[i][j] == 1) fresh++;
            }
        }
        int minutes = -1;
        if(fresh == 0) return 0;
        while(!q.empty()) {
            int size = q.size();
            minutes++;
            for(int i = 0; i < size; i++) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(auto &dir : directions) {
                int mrow = r + dir[0];
                int ncol = c + dir[1];
                if(mrow >= 0 && mrow < m && ncol >= 0 && ncol < n && grid[mrow][ncol] == 1) {
                    fresh--;
                    grid[mrow][ncol] = 2;
                    q.push({mrow, ncol});
                }
            }
        }
        }
        if(fresh == 0) return minutes;
        return -1;
    }
};