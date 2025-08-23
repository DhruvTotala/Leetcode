class Solution {
public:

    void recur(vector <int>& nums, int idx, vector <int> temp, vector<vector<int>>& ans) {
        if(idx >= nums.size()) {
            ans.push_back(temp);
            return;
        }

        // not take
        recur(nums, idx + 1, temp, ans);
        // take
        temp.push_back(nums[idx]);
        recur(nums, idx + 1, temp, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector <vector<int>> ans;
        vector <int> temp;
        recur(nums, 0, temp, ans);
        return ans;
    }
};