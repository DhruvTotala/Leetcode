class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        vector <int> ans;
        sort(nums.begin(), nums.end());
        int a = nums[0];
        int b = nums[n - 1];
        unordered_map <int, int> mp;
        for(int it : nums) {
            mp[it]++;
        }
        for(int i = a; i <= b; i++) {
            if(mp.find(i) == mp.end()) {
                ans.push_back(i);
            } 
        }
        return ans;
    }
};