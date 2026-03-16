class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> array(n, vector<int> (n));
        for (int i = 0; i<n; i++) {
            array[0][i] = matrix[0][i];
        }

        for (int row = 1; row<n; row++) {
            for (int col = 0; col<n; col++) {
                int left = (col == 0) ? INT_MAX : array[row-1][col-1];
                int top = array[row-1][col];
                int right = (col == n-1) ? INT_MAX : array[row-1][col+1];
                array[row][col] = matrix[row][col] + min({left, top, right});
            }
        }

        int minSum = INT_MAX;
        for (int i = 0; i<n; i++) {
            minSum = min(minSum, array[n-1][i]);
        }

        return minSum;
    }
};