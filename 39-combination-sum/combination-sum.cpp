class Solution {
public:

    void findcombinations(int idx, vector <int>& candidates, vector<vector<int>>& ans, vector <int>& ds, int target) {
        if(idx == candidates.size()) {
            if(target == 0) ans.push_back(ds);
            return;
        } 

        if(candidates[idx] <= target) {
            ds.push_back(candidates[idx]);
            findcombinations(idx, candidates, ans, ds, target - candidates[idx]);
            ds.pop_back();
        }
        findcombinations(idx + 1, candidates, ans, ds, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector <int> ds;
        findcombinations(0, candidates, ans, ds, target);
        return ans;
    }
};