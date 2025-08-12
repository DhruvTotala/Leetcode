class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int ans;
        int len = n * (k + 1);
        unordered_map <int, int> mp;
        for(auto it : arr) mp[it]++;
        vector <int> temp;
        for(int i = 1; i <= len; i++) {
            if(mp[i] == 0) temp.push_back(i);
        }
        for(int i = 0; i < temp.size(); i++) {
            if((i + 1 == k)) {
                ans = temp[i];
                break;
            }
        } 
        return ans;
    }
};