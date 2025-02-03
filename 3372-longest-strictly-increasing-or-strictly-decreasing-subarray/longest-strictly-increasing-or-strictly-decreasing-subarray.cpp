class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if (nums.empty()) return 0;

        int max_length = 1;
        int inc_count = 1, dec_count = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                inc_count += 1;
                dec_count = 1;  // Reset decreasing count
            } 
            else if (nums[i] < nums[i - 1]) {
                dec_count += 1;
                inc_count = 1;  // Reset increasing count
            } 
            else {  // If nums[i] == nums[i-1], reset both counts
                inc_count = 1;
                dec_count = 1;
            }
            max_length = max(max_length, max(inc_count, dec_count));
        }
        return max_length;
    }
};
