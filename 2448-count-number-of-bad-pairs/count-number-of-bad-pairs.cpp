class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
    long long  n = nums.size();
    long long  tp = (n * (n - 1)) / 2;
    long long gp = 0;
    unordered_map <long long , long long> mp; 
    for(int i = 0; i < n; i++){
        long long diff = nums[i] - i;
        gp += mp[diff];
        mp[diff] ++;
    }
    return tp - gp;    
    }
};