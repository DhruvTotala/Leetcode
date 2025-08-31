class Solution {
public:

    bool issafe(vector<string>& s, int row, int col, int n) {
        for(int i = 0; i < n; i++) {
            if(s[row][i] == 'Q') return false; // horizontal
            if(s[i][col] == 'Q') return false; // vertical
        }
        
        for(int i = row, j = col; i >= 0 && j >= 0; j--, i--) {
            if(s[i][j] == 'Q') return false;
        }

        for(int i = row, j = col; i >= 0 && j < n; j++, i--) {
            if(s[i][j] == 'Q') return false;
        }
    return true;
    }

    void solve(vector<string>& s, int row, int n, vector<vector<string>>& ans) {
        
        if(row == n) {
            ans.push_back({s});
            return;
        }

        for(int j = 0; j < n; j++) {
            if(issafe(s, row, j, n)) {
                s[row][j] = 'Q';
                solve(s, row + 1, n, ans);
                s[row][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> s(n, string(n, '.'));
        vector<vector<string>> ans;
        solve(s, 0, n, ans);
        return ans;
    }
};