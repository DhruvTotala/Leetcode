class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        int i = 0;
        while(i < n) {
            if(nums[i] == 0){
                if(i > n - 3) return -1;
                nums[i] ^= 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                count ++;
            }
            i++;
            } 
        return count;
    }
};