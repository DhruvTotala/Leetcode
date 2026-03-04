class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int count = 0;
        int m = mat.size();
        int n = mat[0].size();
        vector <int> rowarray(m, 0);
        vector <int> colarray(n, 0);
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(mat[row][col] == 1) {
                    rowarray[row]++;
                    colarray[col]++;
                }
            }
        }
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(mat[row][col] == 1 && rowarray[row] == 1 && colarray[col] == 1) {
                    count++;
                }
            }
        }
        return count;
    }
};