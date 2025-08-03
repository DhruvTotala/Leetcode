class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;

        if (n == 0) return result;

        sort(nums.begin(), nums.end());

        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                cnt++;
            } else {
                if (cnt > n / 3) {
                    result.push_back(nums[i - 1]);
                }
                cnt = 1;  // reset count for the new number
            }
        }

        // Final group check
        if (cnt > n / 3) {
            result.push_back(nums[n - 1]);
        }

        return result;
    }
};
