class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
    int count = 0;
    int m = grid.size();
    int n = grid[0].size();
    for(int i = 0; i < m; i++){
       for(int j = 0; j < n; j++){
        if(grid[i][j] == 1){
            bool servers = false;
            for(int col = 0; col < n; col++){
                if(grid[i][col] == 1 && col != j) {
                    servers = true;
                    break;
            }
            }
                if(!servers) {
                    for(int row = 0; row < m; row++){
                        if(grid[row][j] == 1 && row != i){
                            servers = true;
                            break;
                        }
                    }
                }
            if (servers) count++;
          }
       }
    }
    return count;
    }
};