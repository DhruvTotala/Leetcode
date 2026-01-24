class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int max_ans = 0;
        for(int i = 0; i < n / 2; i++) {
            max_ans = max(max_ans, nums[i] + nums[n - 1 - i]);
        }
        return max_ans;
    }
};