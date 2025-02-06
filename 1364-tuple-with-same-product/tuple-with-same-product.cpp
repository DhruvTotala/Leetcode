class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    sort(nums.begin(), nums.end());
    unordered_map <int, int> mp;
    for(int i = 0; i < n; i++){
    for(int j = i + 1; j < n; j++){
        int prod = nums[i] * nums[j];
        mp[prod]++;
    }
    }
    for(auto it : mp){
        int num = it.first;
        int freq = it.second;
        ans += (freq * (freq - 1)) / 2;
    }
    return ans * 8;
    }
};