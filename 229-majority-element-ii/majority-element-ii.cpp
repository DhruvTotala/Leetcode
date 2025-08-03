class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector <int> result;
        unordered_map <int, int> mp;
        for(auto it : nums) mp[it]++;
        for(auto it : mp) {
            if(it.second > (n / 3)) result.push_back(it.first);
        }
        return result;
    }
};