class Solution {
public:
    typedef long long ll;
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector <ll> rowsum(m, 0);
        vector <ll> colsum(n, 0);
        ll total = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                total += grid[i][j];
                rowsum[i] += grid[i][j];
                colsum[j] += grid[i][j];
            }
        }
        if(total % 2 != 0) return false;
        //horizontal
        ll upper = 0;
        for(int i = 0; i < m - 1; i++) {
            upper += rowsum[i];
            if(total - upper == upper) return true;
        }
        //vertical
        ll left = 0;
        for(int j = 0; j < n - 1; j++) {
            left += colsum[j];
            if(left == total - left) return true;
        }
        return false;
    }
};