class Solution {
public:

    vector<vector<int>> res;

    void permute(int n, int idx, vector <int>& nums) {
        if(idx == n) {
            res.push_back(nums);
            return;
        }

        unordered_set<int> used;

        for(int i = idx; i < n; i++) {

            if (used.count(nums[i])) continue;

            used.insert(nums[i]);
            swap(nums[i], nums[idx]);
            permute(n, idx + 1, nums);
            swap(nums[i], nums[idx]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        // sort(nums.begin(), nums.end());
        permute(n, 0, nums);
        return res;
    }
};