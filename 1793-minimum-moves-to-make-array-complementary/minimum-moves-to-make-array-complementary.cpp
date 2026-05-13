class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> diff(2 * limit + 2, 0);

        for (int i = 0; i < n / 2; i++) {
            int a = nums[i], b = nums[n - 1 - i];
            int low = min(a, b) + 1, high = max(a, b) + limit, sum = a + b;

            diff[2] += 2;
            diff[low] -= 1;
            diff[high + 1] += 1;
            diff[sum] -= 1;
            diff[sum + 1] += 1;
        }

        int ans = INT_MAX, cur = 0;
        for (int s = 2; s <= 2 * limit; s++) {
            cur += diff[s];
            ans = min(ans, cur);
        }
        return ans;
    }
};