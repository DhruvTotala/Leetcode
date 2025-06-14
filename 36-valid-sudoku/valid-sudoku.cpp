class Solution {
public:


    bool Validbox(vector<vector<char>>& board, int sr, int er, int sc, int ec) {
         set <char> st;
         for(int i = sr; i <= er; i++) {
            for(int j = sc; j <= ec; j++) {
                if(board[i][j] == '.') continue;
                if(st.find(board[i][j]) != st.end()) return false;
                st.insert(board[i][j]);
            }
         }
         return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            unordered_set <char> st;
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;
                if(st.find(board[i][j]) != st.end()) return false;
                st.insert(board[i][j]);
            }
        }

        // for columns
        for(int i = 0; i < 9; i++) {
            unordered_set <char> st;
            for(int j = 0; j < 9; j++) {
                if(board[j][i] == '.') continue;
                if(st.find(board[j][i]) != st.end()) return false;
                st.insert(board[j][i]);
            }
        }

        for(int sr = 0; sr < 9; sr += 3) {
            int er = sr + 2;
            for(int sc = 0; sc < 9; sc += 3) {
                int ec = sc + 2;
                if(!(Validbox(board, sr, er, sc, ec))) return false;
            }
        }
        return true;
    }
};