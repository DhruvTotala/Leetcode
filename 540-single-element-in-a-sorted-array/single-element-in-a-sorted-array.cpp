class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    unordered_map <int, int> mp;
    for(auto it : nums) mp[it] ++;
    for(auto it : nums) if(mp[it] == 1) return it; 
    return -1;  
    }
};