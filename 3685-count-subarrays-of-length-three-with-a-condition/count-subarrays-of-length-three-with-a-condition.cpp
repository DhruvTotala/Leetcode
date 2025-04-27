class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                for(int k = j + 1; k < n; k++) {
                    if((abs(i - j) == abs(j - k)) && (abs(i - k) == 2)) {
                        int sum = nums[i] + nums[k];
                        if(2 * (nums[i] + nums[k]) == nums[j]) count++;
                    } 
                }
            }
        }
        return count;
    }
};