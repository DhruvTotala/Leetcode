class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 0; i + 2 * k <= n; i++) {
            bool ok1 = true, ok2 = true;
            for(int a = i; a < i + k - 1; a++) {
                if(nums[a] >= nums[a + 1]) {
                    ok1 = false;
                    break;
                }
            }
            for(int b = i + k; b < i + 2 * k - 1; b++) {
                if(nums[b] >= nums[b + 1]) {
                    ok2 = false;
                    break;
                }
            }
            if(ok1 && ok2) return true;
        }
        return false;
    }
};