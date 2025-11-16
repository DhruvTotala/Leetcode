class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        long long prod = 1;
        int l = 0;
        for(int r = 0; r < n; r++) {
            prod *= nums[r];
            while(prod >= k && l <= r) {
                prod /= nums[l];
                l++;
            }       
            ans += r - l + 1;
        }
        return ans;
    }
};