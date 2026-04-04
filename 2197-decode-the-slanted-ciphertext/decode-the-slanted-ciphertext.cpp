class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if(rows == 0) return "";
        int n = encodedText.size();
        string ans = "";
        int cols = n / rows;
        vector<vector<char>> mat(rows, vector<char>(cols));
        int idx = 0;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                mat[i][j] = encodedText[idx++];
            }
        }
        for(int st = 0; st < cols; st++) {
            int i = 0;
            int j = st;
            while(i < rows && j < cols) {
                ans += mat[i][j];
                i++;
                j++;
            }
        }
        while(!ans.empty() && ans.back() == ' ') ans.pop_back();
        return ans;
    }
};