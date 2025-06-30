class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;

        for (int i = 0; i < n; ++i) {
            int count = 0;
            bool hasNeighbor = false;

            for (int j = 0; j < n; ++j) {
                if (nums[j] == nums[i] || nums[j] == nums[i] + 1) {
                    count++;
                    if (nums[j] != nums[i]) hasNeighbor = true;
                }
            }

            if (hasNeighbor)
                maxLen = max(maxLen, count);
        }

        return maxLen;
    }
};
