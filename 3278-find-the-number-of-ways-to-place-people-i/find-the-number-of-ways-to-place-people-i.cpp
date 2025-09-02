class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) {
                    continue;
                }
                int xi = points[i][0];
                int yi = points[i][1];
                int xj = points[j][0];
                int yj = points[j][1];
                if((xi <= xj) && (yi >= yj)) {
                    bool valid = true;

                    for(int k = 0; k < n; k++) {
                        if(k == i || k == j) continue;
                        int xk = points[k][0];
                        int yk = points[k][1];
                        if(xi <= xk && xk <= xj && yj <= yk && yk <= yi) {
                            valid = false;
                            break;
                        }
                    }
                    if(valid) count++;                   
                }
            }
        }
        return count;
    }
};