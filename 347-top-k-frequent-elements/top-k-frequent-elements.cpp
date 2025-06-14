class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map <int, int> mp;
        for(auto it : nums) mp[it]++;
        vector <pair<int, int>> ans(mp.begin(), mp.end());
        sort(ans.begin(), ans.end(), [](pair<int, int>& a, pair<int, int>& b){
            return a.second > b.second;
        });
        vector <int> res;
        for(int i = 0; i < k; i++) {
            res.push_back(ans[i].first);
        }
        return res;
    }
};