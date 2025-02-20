class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector <int> ans(n);
        vector <int> psum(n,1);
        vector <int> ssum(n,1);
        for(int i = 1; i < n; i++) psum[i] = psum[i - 1] * nums[i - 1];
        for(int i = n - 2; i >= 0; i--) ssum[i] = ssum[i + 1] * nums[i + 1];
        for(int i = 0; i < n; i++) ans[i] = psum[i] * ssum[i];
        return ans;
    }
};