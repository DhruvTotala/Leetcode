class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    bool detectbfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        queue<tuple<int, int, int, int>> q;
        q.push({i, j, -1, -1});
        visited[i][j] = true;
        while(!q.empty()) {
            auto[curr_i, curr_j, prev_i, prev_j] = q.front();
            q.pop();
            for(auto &dir : directions) {
                int new_i = curr_i + dir[0];
                int new_j = curr_j + dir[1];

                if(new_i >= 0 && new_j >= 0 && new_i < m && new_j < n && grid[new_i][new_j] == grid[curr_i][curr_j]) {
                    if(new_i == prev_i && new_j == prev_j) continue;
                    if(visited[new_i][new_j]) return true;
                    visited[new_i][new_j] = true;
                    q.push({new_i, new_j, curr_i, curr_j});
                }
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j] && detectbfs(i, j, grid, visited)) return true;
            }
        }
        return false;
    }
};