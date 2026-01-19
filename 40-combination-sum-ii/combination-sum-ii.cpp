class Solution {
public:
    vector<vector<int>> ans;
    void helper(int idx, vector <int>& candidates, vector<vector<int>>& ans, int target, vector <int>& ds) {
        if(target < 0) return;
        if(target == 0) {
            ans.push_back(ds);
            return;
        }
        for(int i = idx; i < candidates.size(); i++) {
            if(i > idx && candidates[i] == candidates[i - 1]) continue;
            ds.push_back(candidates[i]);
            helper(i + 1, candidates, ans, target - candidates[i], ds);
            ds.pop_back();
        }
       
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector <int> ds;
        sort(candidates.begin(), candidates.end());
        helper(0, candidates, ans, target, ds);
        return ans;
    }
};