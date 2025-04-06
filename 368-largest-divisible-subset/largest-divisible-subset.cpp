class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n == 0) {
            return {};
        }
        vector<int> dp(n, 1);
        vector<int> parent(n, -1);
        int max_len = 1;
        int max_index = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                        if (dp[i] > max_len) {
                            max_len = dp[i];
                            max_index = i;
                        }
                    }
                }
            }
        }

        vector<int> ans;
        int current = max_index;
        while (current != -1) {
            ans.push_back(nums[current]);
            current = parent[current];
        }
        return ans;
    }
};