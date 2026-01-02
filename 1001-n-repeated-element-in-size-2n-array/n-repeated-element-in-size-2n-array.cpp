class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        unordered_map <int, int> mp;
        for(auto it : nums) mp[it]++;
        for(auto it : mp) {
            if((it.second * 2) == n) return it.first;
        }
        return -1;
    }
};