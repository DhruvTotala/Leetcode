class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int zeroes_count = 0;
        int max_len = 0;
        while(r < n) {
            if(nums[r] == 0) zeroes_count++;
            if(zeroes_count > k) {
                if(nums[l] == 0) zeroes_count--;
                l++;
            } 
            if(zeroes_count <= k) {
                int len = r - l + 1;
                max_len = max(max_len, len);
            }
            r++;
        }
        return max_len;
    }
};