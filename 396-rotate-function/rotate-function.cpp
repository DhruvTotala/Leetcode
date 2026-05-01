class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int F = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            F += i * nums[i];
        }
        int ans = F;
        for(int k = 0; k <= n - 1; k++) {
            int new_F = F + sum - n * nums[n - 1 - k];
            ans = max(ans, new_F);
            F = new_F;
        }
        return ans;
    }
};