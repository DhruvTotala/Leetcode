class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int odd_count = 0;
        int ans = 0;
        unordered_map <int, int> mp;
        mp[0] = 1;
        for(int i = 0; i < n; i++) {
            odd_count += (nums[i] % 2);
            if(mp.count(odd_count - k)) {
                ans += mp[odd_count - k];
            }
            mp[odd_count]++;
        }
        return ans;
    }
};