class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++) cout << nums[i];
    }
};