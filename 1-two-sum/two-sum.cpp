class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    vector <int> ans;
    unordered_map <int, int> mp;
    for(int i = 0; i < n; i++){
        int k = target - nums[i];
        if(mp.find(k) != mp.end()){
        ans.push_back(mp[k]);
        ans.push_back(i); 
        }
        else mp[nums[i]] = i;
    }
    return ans;
    } 
};