class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int curr_run = 1;
        int prev_run = 0;
        int ans = 0;
        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i - 1]) curr_run++;
            else {
                prev_run = curr_run;
                curr_run = 1;
            }
            ans = max(ans, curr_run / 2);
            ans = max(ans, min(prev_run, curr_run));
        }
        return ans;
    }
};