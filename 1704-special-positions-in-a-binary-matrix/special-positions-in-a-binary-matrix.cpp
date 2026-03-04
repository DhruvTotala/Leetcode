class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int count = 0;
        int m = mat.size();
        int n = mat[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) continue;
            bool isokay = true;
            for(int r = 0; r < m; r++) {
                if(r != i && mat[r][j] == 1) {
                    isokay = false;
                    break;
                }
            }
            for(int c = 0; c < n; c++) {
                if(c != j && mat[i][c] == 1) {
                    isokay = false;
                    break;
                }
            }
            if(isokay) count++;
        }
        }
        return count;
    }
};