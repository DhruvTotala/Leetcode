class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(vis[i][j]) continue;

                queue<tuple<int,int,int,int>> q;
                q.push({i, j, -1, -1});
                vis[i][j] = true;

                while(!q.empty()) {
                    auto [x, y, px, py] = q.front();
                    q.pop();

                    for(int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                        if(grid[nx][ny] != grid[x][y]) continue;

                        if(!vis[nx][ny]) {
                            vis[nx][ny] = true;
                            q.push({nx, ny, x, y});
                        }
                        else if(nx != px || ny != py) {
                            return true;
                        }
                    }
                }
            }
        }

        return false;
    }
};