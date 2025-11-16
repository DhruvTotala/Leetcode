class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        if(k <= 1) return 0;
        int ans = 0;
        long long prod = 1;
        int l = 0;
        int r = 0;
        while (r < n) {
            prod *= nums[r];
            while(prod >= k) {
                prod /= nums[l];
                l++;
            }       
            ans += r - l + 1;
            r++;
        }
        return ans;
    }
};