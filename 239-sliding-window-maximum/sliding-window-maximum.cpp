class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector <int> ans;
        map <int, int> mp;
        for(int i = 0; i < k; i++) {
            mp[nums[i]]++;
        }
        int l = 0;
        int r = k - 1;
        while(r < n) {
            ans.push_back(mp.rbegin() -> first);
            r++;

            if(r < n) {
                mp[nums[r]]++;
            }
            mp[nums[l]]--;
            if(mp[nums[l]] == 0) mp.erase(nums[l]);
            l++;
        }
        return ans;
    }
};