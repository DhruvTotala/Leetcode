class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    int count = 1;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    if(nums.empty()) return 0;
    int ans = 1;
    for(int i = 1; i < n; i++){
        if((nums[i] - nums[i - 1]) == 1) count++;
        else if(nums[i] - nums[i - 1] == 0) continue;
        else count = 1;
        ans = max(ans , count);
    }    
    return ans;
    }
};