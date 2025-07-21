class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        vector <int> ans;
        int n = arr.size();
        unordered_map <int, int> mp;
        for(int i = 0; i < n; i++) {
            if(mp.find(target - arr[i]) != mp.end()) {
                ans.push_back(i);
                ans.push_back(mp[target - arr[i]]);
            }
        mp[arr[i]] = i;
        }
        return ans;
    }
};