class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map <int, int> mp;
        for(auto it : nums) mp[it]++;
        for(auto it : mp) {
            if(it.second >= 2) return true;
        }
        return false;
    }
};