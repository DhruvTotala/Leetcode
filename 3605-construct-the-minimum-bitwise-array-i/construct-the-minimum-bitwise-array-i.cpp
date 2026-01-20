class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int temp = nums[i];
            for(int j = 1; j < nums[i]; j++) {
                if((j | (j + 1)) == nums[i]) {
                    nums[i] = j;
                    break;
                }
            }
            if(nums[i] == temp) nums[i] = -1;
        }
        return nums;
    }
};