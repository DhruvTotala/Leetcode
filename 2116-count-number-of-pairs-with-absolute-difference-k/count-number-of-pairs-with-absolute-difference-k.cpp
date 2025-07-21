class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int count = 0;

        for (int num : nums) {
            count += mp[num - k] + mp[num + k];
            mp[num]++;
        }

        return count;
    }
};
