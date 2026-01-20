class Solution {
public:
    vector<vector<int>> ans;
    void helper(int i, int k, int n, int sum, vector <int>& ds) {
        if(k < 0) return;
        if(sum == n) {
            if(k == 0) {
                ans.push_back(ds);
            }
            return;
        }
        if(i == 10) return;
        
        sum += i; // pick
        ds.push_back(i);
        helper(i + 1, k - 1, n, sum, ds);
        sum -= i;
        ds.pop_back();

        // not pick
        helper(i + 1, k, n, sum, ds);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector <int> ds;
       helper(1, k, n, 0, ds);
       return ans;
    }
};