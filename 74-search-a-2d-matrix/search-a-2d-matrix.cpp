class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int row = n;
        for(int i = 0; i < n; i++) {
            if(matrix[i][0] > target) {
                row = i - 1;
                break;
            } 
            if(matrix[i][0] == target) return true;
        }
        if(row < 0) return false;
        if(row == n) row = n - 1;
        int low = 0;
        int high = m - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(matrix[row][mid] == target) return true;
            else if(matrix[row][mid] > target) high = mid - 1;
            else low = mid + 1; 
        }
        return false;
    }
};