class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    int n = grid.size();
    unordered_map <int, int> mp;
    for(auto it : grid){
        for(int num : it) mp[num] ++;
    }
    vector <int> ans;
    int r = -1;
    int m = -1;
    for(int i = 1; i <= n * n; i++){
        if(mp[i] == 2) r = i;
        if(mp[i] == 0) m = i;
    }
    ans.push_back(r);
    ans.push_back(m);
    return ans;
    }
};