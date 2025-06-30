class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        unordered_map <int, int> mp;
        for(auto &it : nums) mp[it]++;
        int ans = 0;
        for(auto& [num, count] : mp) {
            if(mp.count(num + 1)) {
                ans = max(ans, count + mp[num + 1]);
            }
        }
        return ans;
    }
};