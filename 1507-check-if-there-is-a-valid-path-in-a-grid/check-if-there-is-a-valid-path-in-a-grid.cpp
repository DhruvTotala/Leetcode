class Solution {
public:
    unordered_map<int, vector<vector<int>>> directions = {
        {1, {{0,-1},{0,1}}},
        {2, {{1,0},{-1,0}}},
        {3, {{1,0},{0,-1}}},
        {4, {{1,0},{0,1}}},
        {5, {{0,-1},{-1,0}}},
        {6, {{-1,0},{0,1}}}
    };

    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n,false));
        queue<pair<int,int>> q;

        q.push({0,0});
        visited[0][0] = true;

        while(!q.empty()) {
            auto [r,c] = q.front();
            q.pop();

            if(r == m-1 && c == n-1) return true;

            for(auto &dir : directions[grid[r][c]]) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if(nr < 0 || nc < 0 || nr >= m || nc >= n || visited[nr][nc])
                    continue;

                for(auto &backdir : directions[grid[nr][nc]]) {
                    if(nr + backdir[0] == r && nc + backdir[1] == c) {
                        visited[nr][nc] = true;
                        q.push({nr,nc});
                        break;
                    }
                }
            }
        }

        return false;
    }
};