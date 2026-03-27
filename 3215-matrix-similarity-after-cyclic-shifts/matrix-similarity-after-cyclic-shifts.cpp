class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        k %= n;
        if(k == 0) return true;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int curridx = j;
                int finalidx;
                if(i % 2 == 0) { // left shift
                    finalidx = (j + k) % n;
                } else { // right shift
                    finalidx = (j - k + n) % n;
                }
                if(mat[i][curridx] != mat[i][finalidx]) return false;
            }
        }
        return true;
    }
};