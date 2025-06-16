class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int max_diff = -1;
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                if(nums[i] < nums[j]) {
                    max_diff = max(nums[j] - nums[i], max_diff);
                }
            }
        }
        return max_diff;
    }
};