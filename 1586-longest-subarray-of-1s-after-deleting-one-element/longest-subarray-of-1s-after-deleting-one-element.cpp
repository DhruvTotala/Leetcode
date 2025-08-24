class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zero_count = 0;
        int len = 0;
        int i = 0;
        for(int j = 0; j < nums.size(); j++) {
            zero_count += (nums[j] == 0);

            while(zero_count > 1) {
                zero_count -= (nums[i] == 0);
                i++;
            }
            len = max(len, j - i);
        }
        return len;
    }
};