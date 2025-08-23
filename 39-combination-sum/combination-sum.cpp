class Solution {
public:

    void recur(int idx, int target, vector <int>& candidates, vector <int>& temp, vector<vector<int>>& ans) {
        
        if(target == 0) {
            ans.push_back(temp);
            return;
        }
        
        if(target < 0) return;
        if(idx >= candidates.size()) {
            return;
        }



        // no take
        recur(idx + 1, target, candidates, temp, ans);

        // take
        temp.push_back(candidates[idx]);
        recur(idx, target - candidates[idx], candidates, temp, ans);
        temp.pop_back();
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector <int> temp;
        recur(0, target, candidates, temp, ans);

        return ans;
    }
};