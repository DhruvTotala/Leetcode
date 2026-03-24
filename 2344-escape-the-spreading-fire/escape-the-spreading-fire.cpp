class Solution {
public:
    // Directions arrays for 4 possible movements (right, down, left, up)
    int dRow[4] = {0, 1, 0, -1};
    int dCol[4] = {1, 0, -1, 0};

    bool canReach(vector<vector<int>>& grid, int delay) {
        queue<tuple<int, int, int>> q; // Using tuple for clarity
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int> (n, 0));
        q.push({delay, 0, 0});

        while(!q.empty()) {
            auto [t, x, y] = q.front();
            q.pop();
            vis[x][y] = 1;
            
            if(x == m - 1 && y == n - 1 && t <= grid[x][y]) return true;
            if(grid[x][y] <= t) continue;

            for(int i = 0; i < 4; i++) {
                int nx = x + dRow[i], ny = y + dCol[i];
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] != -1 && t < grid[nx][ny] && !vis[nx][ny]) {
                    q.push({t + 1, nx, ny});
                }
            }
        }
        return false;
    }

    int maximumMinutes(vector<vector<int>>& grid) {
        queue<tuple<int, int, int>> q;
        int m = grid.size(), n = grid[0].size();

        // Initialize fire spread grid
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    q.push({0, i, j}); // Fire starts
                } else if(grid[i][j] == 2) {
                    grid[i][j] = -1;  // Obstacle
                } else {
                    grid[i][j] = INT_MAX; // Safe initially
                }
            }
        }

        // BFS to calculate fire spread time
        while(!q.empty()) {
            auto [t, x, y] = q.front();
            q.pop();
            grid[x][y] = t;
            
            for(int i = 0; i < 4; i++) {
                int nx = x + dRow[i], ny = y + dCol[i];
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == INT_MAX) {
                    q.push({t + 1, nx, ny});
                }
            }
        }

        // Binary Search for maximum delay
        int s = 0, e = m * n, ans = -1;
        while(s <= e) {
            int mid = s + (e - s) / 2;
            if(canReach(grid, mid)) {
                ans = mid;
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        // Check if waiting indefinitely is possible
        return canReach(grid, 1e5) ? 1e9 : ans;
    }
};