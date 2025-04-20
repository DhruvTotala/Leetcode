class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();
        unordered_map <int, int> mp;
        for(auto it : answers) mp[it] ++;
        
        int total_r = 0;
        for(auto it : mp) {
            int x = it.first;
            int count = it.second;
            int grp_size = ceil((double)count / (x + 1));
            total_r += grp_size * (x + 1);
        }
        return total_r;
     }
};