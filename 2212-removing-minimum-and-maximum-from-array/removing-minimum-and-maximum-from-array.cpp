class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int min_idx = min_element(nums.begin(), nums.end()) - nums.begin();
        int max_idx = max_element(nums.begin(), nums.end()) - nums.begin();

        int left_idx = min(min_idx, max_idx);
        int right_idx = max(min_idx, max_idx);

        return min({left_idx + 1 + n - right_idx, right_idx + 1, n - left_idx});

    }
};