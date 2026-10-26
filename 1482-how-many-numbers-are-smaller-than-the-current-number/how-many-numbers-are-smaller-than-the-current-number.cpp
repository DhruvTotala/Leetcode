class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        unordered_map <int, int> mp;
        vector <int> vec = nums;
        int n = nums.size();

        sort(vec.begin(), vec.end());
        for(int i = n - 1; i >= 0; i--) {
            mp[vec[i]] = i;
        }

        for(int i = 0; i < n; i++) {
            nums[i] = mp[nums[i]];
        }
        return nums;
    }
};