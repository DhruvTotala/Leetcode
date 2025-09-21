class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int sum = 0;
        int count = 0;
        unordered_map <int, int> mp;
        mp[sum] = 1;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            sum += nums[i] % 2;

            if(mp.find(sum - k) != mp.end()) {
                count += mp[sum - k];
            }
            mp[sum]++;
        }
        return count;
        
    }
};