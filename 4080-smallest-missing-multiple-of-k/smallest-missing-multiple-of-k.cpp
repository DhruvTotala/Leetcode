class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int max_ele = *max_element(nums.begin(), nums.end());
        unordered_map <int, int> mp;
        for(auto it : nums) mp[it]++;
        int i = k;
        while(i <= max_ele) {
            if(mp.find(i) == mp.end()) return i;
            i += k;
        }
        return i;
    }
};