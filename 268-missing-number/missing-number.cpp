class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int nums_xor = nums[0];
        for(int i = 1; i < n; i++) {
            nums_xor ^= nums[i];
        }
        int size_xor = 0;
        for(int i = 1; i <= n; i++) {
            size_xor ^= i;
        }
        return size_xor ^ nums_xor;
    }
};