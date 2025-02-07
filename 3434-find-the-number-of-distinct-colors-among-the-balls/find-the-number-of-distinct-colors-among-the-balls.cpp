class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
    int m = queries.size();
    vector <int> ans(m);
    unordered_map <int, int> bmp;
    unordered_map <int, int> cmp;
    for(int i = 0; i < m; i++){
         int ball = queries[i][0];
         int color = queries[i][1];
         if(bmp.count(ball)){
            int prevcolor = bmp[ball];
            cmp[prevcolor] --;
         if(cmp[prevcolor] == 0) cmp.erase(prevcolor);
         }
        bmp[ball] = color;
        cmp[color] ++;
        ans[i] = cmp.size();
    }
    return ans;
    }
};