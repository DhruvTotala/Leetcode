class Solution {
public:

    void sortDiagonal(int row, int col, vector<vector<int>>& grid, bool asc) {
        int n = grid.size();
        int i = row;
        int j = col;
        vector <int> vec;
        while(i < n && j < n) {
            vec.push_back(grid[i][j]);
            i++;
            j++;
        }
        if(asc) {
            sort(vec.begin(), vec.end());
        } else {
            sort(vec.rbegin(), vec.rend());
        }

        i = row;
        j = col;
        for(int& val : vec) {
            grid[i][j] = val;
            i++;
            j++;
        }
    }

    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector <int>> ans;
        
        // Bottom left diaginal
        for(int row = 0; row < n; row++) {
            sortDiagonal(row, 0, grid, false);
        }        
        
        // Top right diagonal
        for(int col = 1; col < n; col++) {
            sortDiagonal(0, col, grid, true);
        } 
        return grid;
    }
};