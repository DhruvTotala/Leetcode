class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inicolor = image[sr][sc];
        if (image[sr][sc] == color) return image;
        int n = image.size();
        int m = image[0].size();
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        image[sr][sc] = color;

        while(!q.empty()){
            auto [row, col] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == inicolor) {
                    q.push({nrow, ncol});
                    image[nrow][ncol] = color;
                }
            }
        }
        return image;
    }
};