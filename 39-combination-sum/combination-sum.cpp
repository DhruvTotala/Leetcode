class Solution {
public:
    vector<vector<int>> ans;
    vector <int> ds;
    void helper(vector <int>& candidates, int target, vector<vector<int>>& ans, vector <int> &ds, int idx) {
       if(idx == candidates.size()) {
        if(target == 0) ans.push_back(ds);
        return;
       } 
       if(candidates[idx] <= target) {
        ds.push_back(candidates[idx]);
        helper(candidates, target - candidates[idx], ans, ds, idx);
        ds.pop_back();
       }
       helper(candidates, target, ans, ds, idx + 1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        helper(candidates, target, ans, ds, 0);   
        return ans;
    }
};