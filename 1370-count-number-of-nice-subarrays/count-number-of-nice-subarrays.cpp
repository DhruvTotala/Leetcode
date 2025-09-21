class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, count = 0, sum = 0;
        for (int r = 0; r < n; r++) {
            sum += (nums[r] % 2);
            while (sum > k) {
                sum -= (nums[l] % 2);
                l++;
            }
            count += (r - l + 1); // all subarrays ending at r
        }
        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};
