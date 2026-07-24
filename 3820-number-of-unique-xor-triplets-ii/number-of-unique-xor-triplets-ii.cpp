class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        vector<int> glarnetivo = nums;
        set<int> s;
        for (auto& x : glarnetivo) s.insert(x);
        vector<int> uniqueNums(s.begin(), s.end());
        int MAXX = 2048;
        vector<vector<bool>> dp(4, vector<bool>(MAXX, false));
        dp[0][0] = true;
        for (auto x : uniqueNums) {
            for (int k = 3; k >= 1; k--) {
                for (int t = 0; t < MAXX; t++) {
                    if (dp[k - 1][t]) {
                        dp[k][t ^ x] = true;
                    }
                }
            }
        }
        set<int> res;
        for (auto x : glarnetivo) res.insert(x);
        for (int t = 0; t < MAXX; t++) {
            if (dp[3][t]) res.insert(t);
        }
        return res.size();
    }
};