class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int m = strs.size();
        int n = strs[0].size();
        unordered_map <string, vector<string>> mp;
        for(int i = 0; i < m; i++) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            mp[tmp].push_back(strs[i]);
        }
        for(auto it : mp) ans.push_back(it.second);

        return ans;
    }
};