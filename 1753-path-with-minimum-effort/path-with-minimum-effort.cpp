class Solution {
public:
    typedef pair<int, pair<int, int>> p;
    vector<vector<int>> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        auto issafe = [&](int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n;
        };

        // unordered_map <int, vector<pair<int, int>>> mp;
        // for(auto &h : heights) {
        //     int u = h[0];
        //     int v = h[1];
        //     int wt = h[2];
        //     mp[u].push_back({v, wt});
        //     mp[v].push_back({u, wt});
        // }
        vector<vector<int>>ans(m, vector<int>(n, INT_MAX));
        priority_queue<p, vector<p>, greater <p>> pq;
        ans[0][0] = 0;
        pq.push({0, {0, 0}});
        while(!pq.empty()) {
            int diff = pq.top().first;
            auto corr = pq.top().second;
            int x = corr.first;
            int y = corr.second;
            pq.pop();
            if(x == m - 1 && y == n - 1) return diff;
            for(auto &dir : directions) {
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if(issafe(x_, y_)) {
                    int abs_diff = abs(heights[x][y] - heights[x_][y_]);
                    int max_diff = max(diff, abs_diff);
                    if(ans[x_][y_] > max_diff) {
                        ans[x_][y_] = max_diff;
                        pq.push({max_diff, {x_, y_}});
                    }
                }
            }
        }
        return ans[m - 1][n - 1];
    }
};