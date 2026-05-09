class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        
        int m = grid.size();
        int n = grid[0].size();

        int layers = min(m, n) / 2;

        for(int layer = 0; layer < layers; layer++) {

            vector<int> vals;

            int top = layer;
            int left = layer;

            int bottom = m - layer - 1;
            int right = n - layer - 1;

            // top row
            for(int j = left; j <= right; j++) {
                vals.push_back(grid[top][j]);
            }

            // right column
            for(int i = top + 1; i <= bottom - 1; i++) {
                vals.push_back(grid[i][right]);
            }

            // bottom row
            for(int j = right; j >= left; j--) {
                vals.push_back(grid[bottom][j]);
            }

            // left column
            for(int i = bottom - 1; i >= top + 1; i--) {
                vals.push_back(grid[i][left]);
            }

            int sz = vals.size();
            int start = k % sz;
            int idx = start;

            // top row
            for(int j = left; j <= right; j++) {
                grid[top][j] = vals[idx];
                idx++;
                if(idx == sz){
                    idx = 0;
                }
            }

            // right column
            for(int i = top + 1; i <= bottom - 1; i++) {
                grid[i][right] = vals[idx];
                idx++;
                if(idx == sz){
                    idx = 0;
                }
            }

            // bottom row
            for(int j = right; j >= left; j--) {
                grid[bottom][j] = vals[idx];
                idx++;
                if(idx == sz){
                    idx = 0;
                }
            }

            // left column
            for(int i = bottom - 1; i >= top + 1; i--) {
                grid[i][left] = vals[idx];
                idx++;
                if(idx == sz){
                    idx = 0;
                }
            }
        }

        return grid;
    }
};