class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        vector <int> ans;
        unordered_map <int, int> mp;
        for(auto it : nums) mp[it]++;
        for(auto it : mp) {
            int frq = it.second;
            if(frq == 2) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};