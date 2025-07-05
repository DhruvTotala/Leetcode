class Solution {
public:
    int findLucky(vector<int>& arr) {
        int ans = -1;
        int n = arr.size();
        unordered_map <int, int> mp;
        for(auto it : arr) mp[it]++;
        for(auto it : mp) {
            int num = it.first;
            int freq = it.second;
            if(num == freq) {
                ans = max(ans, num);
            }
        }
        return ans;
    }
};