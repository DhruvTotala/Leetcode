class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double diag_len = INT_MIN;
        int max_area = 0;
        for(vector <int>&d : dimensions) {
            double tmp_len = sqrt(d[0] * d[0] + d[1] * d[1]);
            if(tmp_len > diag_len) {
               diag_len = tmp_len;
               max_area = d[0] * d[1];
            } else if(tmp_len == diag_len) {
                max_area = max(max_area, d[0] * d[1]);
            }
        }
        return max_area;
    }
};