class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map <int, int> mp;
        for(auto it : nums) mp[it] ++;
        for(auto &[key, count] : mp) {
            if(count % 2 != 0) return false;
        }
        return true;
    }
};