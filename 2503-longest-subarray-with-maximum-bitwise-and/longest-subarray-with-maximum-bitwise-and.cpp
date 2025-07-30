class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int max_len = 0;
        int curr_len = 0;
        int max_ele = *max_element(nums.begin(), nums.end());
        for(int i = 0; i < n; i++) {
            if(nums[i] == max_ele) {
                curr_len += 1;
                max_len = max(max_len, curr_len);
            } else {
                curr_len = 0;
            }
        }
        return max_len;
    }
};