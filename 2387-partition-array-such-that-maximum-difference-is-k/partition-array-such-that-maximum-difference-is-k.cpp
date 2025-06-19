class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 1;
        int pre = nums[0];
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] - pre > k) {
                ans++;
                pre = nums[i];
            }
        }
        return ans;
    }
};