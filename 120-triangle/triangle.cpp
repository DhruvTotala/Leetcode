class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> min_elements = triangle[n-1]; // start from bottom row
        
        // move from second last row up to the top
        for (int i = n-2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                min_elements[j] = triangle[i][j] + min(min_elements[j], min_elements[j+1]);
            }
        }
        
        return min_elements[0];
    }
};
