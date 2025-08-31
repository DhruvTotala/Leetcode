class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector <int> ans;
        int n = order.size();
        int m = friends.size();
        unordered_map <int, int> mp;
        for(auto it : friends) mp[it]++;
        for(int i = 0; i < n; i++) {
           if(mp.find(order[i]) != mp.end()) {
            ans.push_back(order[i]);
           }
        }
        return ans;    
    }
};