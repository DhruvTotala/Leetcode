class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size() - 1; 
        int max_ele = *max_element(nums.begin(), nums.end());
        for(int i = 0; i < n; i++) {
            if(nums[i] != i + 1) return false;
        }
        return nums[n] == n;
    }
};