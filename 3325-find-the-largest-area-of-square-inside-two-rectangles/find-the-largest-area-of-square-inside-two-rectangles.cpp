class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        int max_side = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                // topRight 
                int topRight_x = min(topRight[i][0], topRight[j][0]);
                //bottomLeft
                int bottomLeft_x = max(bottomLeft[i][0], bottomLeft[j][0]);
                int w = topRight_x - bottomLeft_x;

                int topRight_y = min(topRight[i][1], topRight[j][1]);
                int bottomLeft_y = max(bottomLeft[i][1], bottomLeft[j][1]);

                int h = topRight_y - bottomLeft_y;
                int side = min(h, w);
                max_side = max(side, max_side);

            }
        }
        return 1LL* max_side * max_side;
    }
};