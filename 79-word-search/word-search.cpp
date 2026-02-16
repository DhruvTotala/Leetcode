class Solution {
public:
    int m, n;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool find(vector<vector<char>>& board, int row, int col, int idx, string& word) {
        if(idx == word.size()) return true;
        if(row < 0 || col < 0 || row >= m || col >= n || board[row][col] == '$') return false;

        if(board[row][col] != word[idx]) return false;

        char temp = board[row][col];
        board[row][col] = '$';
        for(auto &it : directions) {
            int new_row = row + it[0];
            int new_col = col + it[1];

            if(find(board, new_row, new_col, idx + 1, word)) return true; 
        }
        board[row][col] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
         m = board.size();
         n = board[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word[0] && find(board, i, j, 0, word)) return true;
            }
        } 
        return false;
    }
};