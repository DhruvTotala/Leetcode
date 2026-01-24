class Solution {
public:
vector<vector<string>> ans;
int count = 0;
    bool issafe(int row, int col, int n, vector<string>& board) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < col; j++) {
                if(board[i][j] == 'Q') {
                    if(i == row) return false;

                    if(abs(i - row) == abs(j - col)) return false;
                }
            }
        }
        return true;
    }

    void helper(int col, int n, vector <string>& board) {
        if(col == n) {
            ans.push_back(board);
            count++;
            return;
        }
        for(int i = 0; i < n; i++) {
            if(issafe(i, col, n, board)) {
            board[i][col] = 'Q';
            helper(col + 1, n, board);
            board[i][col] = '.';
        }
    }
}

    int totalNQueens(int n) {
        vector<vector<string>> ans;
        vector <string> board(n, string(n, '.'));
        helper(0, n, board);
        return count;
    }
};