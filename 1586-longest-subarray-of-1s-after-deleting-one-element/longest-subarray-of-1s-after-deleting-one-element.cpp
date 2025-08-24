class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zero_count = 0;
        int len = 0;
        int i = 0;
        for(int j = 0; j < nums.size(); j++) {
            if(nums[j] == 0) zero_count++;

            while(zero_count > 1) {
                if(nums[i] == 0) zero_count--;
                i++;
            }
            len = max(len, j - i);
        }
        return len;
    }
};