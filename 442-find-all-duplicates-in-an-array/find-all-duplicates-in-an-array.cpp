class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
    // vector<int> ans;
    // vector <int> visited(nums.size() + 1, 0);
    // for(int i = 0; i < nums.size(); i++){
    //     if(visited[nums[i]] == 0){
    //         for(int j = i + 1; j < nums.size(); j++){
    //             if(nums[i] == nums[j]) ans.push_back(nums[i]);
    //         }
    //         visited[nums[i]] = 1;
    //     }
    // }
    // sort(ans.begin(), ans.end());
    // return ans; 
    vector <int> ans;
    unordered_map <int , int> mp;
    for(auto &x : nums) mp[x]++;
    for(auto it : mp) if(it.second > 1) ans.push_back(it.first);
    return ans;
    }
};