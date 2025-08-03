class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int count = 1;
        int ans = 0;
        sort(nums.begin(), nums.end());
        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[i - 1]) count++;
            else count = 1;
            if(count > (n / 2)) return nums[i];
        } 
        return -1;
    }
};