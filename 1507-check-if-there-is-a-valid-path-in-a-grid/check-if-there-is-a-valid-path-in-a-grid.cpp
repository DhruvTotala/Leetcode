class Solution {
public:
    int m, n;
    unordered_map <int, vector<vector<int>>> directions = {
        {1, {{0, -1}, {0, 1}}},
        {2, {{1, 0}, {-1, 0}}},
        {3, {{1, 0}, {0, -1}}},
        {4, {{1, 0}, {0, 1}}},
        {5, {{0, -1}, {-1, 0}}},
        {6, {{-1, 0}, {0, 1}}},
    };

    bool dfs(vector<vector<bool>>& visited, int r, int c, vector<vector<int>>& grid) {
        if(r == m - 1 && c == n - 1) return true;
        visited[r][c] = true;
        for(auto &dir : directions[grid[r][c]]) {
            int new_r = r + dir[0];
            int new_c = c + dir[1];
            if(new_r < 0 || new_c < 0 || new_r >= m || new_c >= n || visited[new_r][new_c]) {
                continue;
            }
            for(auto &backdir : directions[grid[new_r][new_c]]) {
                if(new_r + backdir[0] == r && new_c + backdir[1] == c) {
                    if(dfs(visited, new_r, new_c, grid)) return true;
                }
            }
        }
        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        return dfs(visited, 0, 0, grid);
    }
};