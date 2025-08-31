class Solution {
public:
    
    bool isValid(vector<vector<char>>& board, int i, int j, int d) {
        for(int k = 0; k < 9; k++) {
            if(board[i][k] == d) return false;
            if(board[k][j] == d) return false;
        }

        int sr = (i / 3) * 3;
        int sc = (j / 3) * 3;

        for(int k = 0; k < 3; k++) {
            for(int l = 0; l < 3; l++) {
                if(board[sr + k][sc + l] == d) {
                    return false;
                }
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') {
                   for(char d = '1'; d <= '9'; d++) {
                      if(isValid(board, i, j, d)) {
                        board[i][j] = d;
                        if(solve(board) == true) {
                            return true;
                        }
                        board[i][j] = '.';
                      }
                   }
                return false;
                }
            }
        }
    return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};