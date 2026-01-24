class Solution {
public:

    bool issafe(int row, int col, int n, vector <string>& board) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < col; j++) {
                if(board[i][j] == 'Q') {
                    if(i == row) return false;

                    if(abs(row - i) == abs(col - j)) return false;
                }
            }
        }
        return true;
    }

    void helper(int col, int n, vector <string>& board, vector<vector<string>>& ans) {
        if(col == n) {
            ans.push_back(board);
            return;
        }
        for(int i = 0; i < n; i++) {
            if(issafe(i, col, n, board)) {
                board[i][col] = 'Q';
                helper(col + 1, n, board, ans);
                board[i][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector <string> board(n, string(n, '.'));
        helper(0, n, board, ans);
        return ans;
    }
};