class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map <int, int> mp;
        for(auto it : nums) mp[it]++;
        int ans = 0;
        for(auto it : mp) {
            int frq = it.second;
            if(frq > (n / 2)) {
                ans = it.first;
                break;
            }
        }
        return ans;
    }
};