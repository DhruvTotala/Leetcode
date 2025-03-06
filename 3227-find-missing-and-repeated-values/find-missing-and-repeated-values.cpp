class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    int n = grid.size();
    unordered_map <int, int> mp;
    for(auto it : grid){
        for(int num : it) mp[num] ++;
    }
    vector <int> ans;
    for(int i = 1; i <= n * n; i++){
        if(mp[i] == 2) ans.push_back(i);
    }
    for(int i = 1; i <= n * n; i++){
        if(mp[i] == 0) ans.push_back(i);
    }
    return ans;
    }
};