class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector <int> ans;
        unordered_map <int, int> mp;
        for(int i = 0; i < n; i++) {
           int complement = target - nums[i];
           if(mp.find(complement) != mp.end()) {
              ans.push_back(mp[complement]);
              ans.push_back(i);
              break;
           }
           mp[nums[i]] = i;
        }
         sort(ans.begin(), ans.end());
         return ans;
    }
};