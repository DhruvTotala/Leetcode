class Solution {
public:
    int countPairs(vector<int>& nums, int maxDiff) {
        int count = 0;
        int i = 0;
        while (i < nums.size() - 1) {
            if (nums[i + 1] - nums[i] <= maxDiff) {
                count++;
                i += 2; // pair formed, skip next
            } else {
                i++;
            }
        }
        return count;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int low = 0, high = nums.back() - nums.front();
        int ans = high;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (countPairs(nums, mid) >= p) {
                ans = mid;
                high = mid - 1; // try smaller maxDiff
            } else {
                low = mid + 1; // need a larger maxDiff
            }
        }

        return ans;
    }
};
