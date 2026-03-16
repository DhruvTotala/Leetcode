class Solution {
public:
    typedef pair<int, pair<int, int>> p;
    vector<vector<int>> directions{{1,1}, {0,1}, {-1,1}, {-1,0}, {-1,-1}, {0,-1}, {1,-1}, {1,0}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(m == 0 || n == 0 || grid[0][0] == 1) return -1;
        auto issafe = [&](int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n;
        };
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        priority_queue <p, vector <p>, greater <p>> pq;
        pq.push({0, {0, 0}});
        result[0][0] = 0;
        while(!pq.empty()) {
            int dist = pq.top().first;
            pair <int, int> node = pq.top().second;
            int x = node.first;
            int y = node.second;
            pq.pop();
            for(auto &dir : directions) {
                int x_ = x + dir[0];
                int y_ = y + dir[1];
                int wt = 1;
                if(issafe(x_, y_) && grid[x_][y_] == 0 && dist + wt < result[x_][y_]) {
                    pq.push({dist + wt, {x_, y_}});
                    result[x_][y_] = dist + wt;
                }
            }
        }
        if(result[m - 1][n - 1] == INT_MAX) return -1;
        return result[m - 1][n - 1] + 1;
    }
};