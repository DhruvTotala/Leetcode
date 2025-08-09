class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int nums_xor = nums[0];
        for(int i = 1; i < n; i++) {
            nums_xor ^= nums[i];
        }
        for(int i = 1; i <= n; i++) {
            nums_xor ^= i;
        }
        return nums_xor;
    }
};