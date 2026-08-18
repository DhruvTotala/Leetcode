class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for(int i = 0; i <= n - k; i++) {
            unordered_set<int> st;
            for(int j = i; j < i + k; j++) {
                if(st.find(nums[j]) == st.end()) {
                    st.insert(nums[j]);
                    mp[nums[j]]++;
                }
            }
        }
        int ans = -1;
        for(auto &it : mp) {
            if(it.second == 1) ans = max(ans, it.first);
        }
        return ans;
    }
};