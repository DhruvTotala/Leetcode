class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        if(n == 0) return 0;
        int max_ans = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 1; i++) {
            if(nums[i + 1] - nums[i] == 1) ans++;
            if(nums[i + 1] == nums[i]) continue;
            if(nums[i + 1] - nums[i] > 1) ans = 0;
            max_ans = max(ans, max_ans);
        }
        return max_ans + 1;
    }
};