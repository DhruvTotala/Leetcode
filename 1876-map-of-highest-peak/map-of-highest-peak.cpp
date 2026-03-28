class Solution {
public:
    vector<vector<int>> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();

        vector<vector<int>> ans(m, vector<int>(n, -1));
        queue <pair<int, int>> q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(isWater[i][j] == 1) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        while(!q.empty()) {
            int kk = q.size();
            while(kk--) {
                auto f = q.front();
                q.pop();
                int x = f.first;
                int y = f.second;
                for(auto &dir : directions) {
                    int x_ = x + dir[0];
                    int y_ = y + dir[1];
                    if(x_ >= 0 && y_ >= 0 && x_ < m && y_ < n && ans[x_][y_] == -1) {
                        ans[x_][y_] = ans[x][y] + 1;
                        q.push({x_, y_});
                    }
                }
            }
        }
        return ans;
    }
};