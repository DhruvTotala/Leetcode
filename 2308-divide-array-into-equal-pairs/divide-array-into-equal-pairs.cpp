class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map <int, int> mp;
        for(auto it : nums) mp[it] ++;
        for(int i = 0; i < n; i++) {
            if(mp[nums[i]] % 2 != 0) return false;
        }
        return true;
    }
};