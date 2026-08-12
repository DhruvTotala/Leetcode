class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int max_len = 0;
        int n = nums.size();
        int l = 0;
        int r = 0;
        unordered_map <int, int> mp;
        while(r < n) {
            mp[nums[r]]++;
            while(mp[nums[r]] > k) {
                mp[nums[l]]--;
                l++;
            }
            max_len = max(max_len, r - l + 1);
            r++;
        }
        return max_len;
    }
};