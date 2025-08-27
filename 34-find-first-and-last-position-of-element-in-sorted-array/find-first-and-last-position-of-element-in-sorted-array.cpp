class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector <int> ans(2, -1);
        int lb = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int ub = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (lb < n && nums[lb] == target) {
            ans[0] = lb;
            ans[1] = ub - 1;
        }
        return ans;
    }
};