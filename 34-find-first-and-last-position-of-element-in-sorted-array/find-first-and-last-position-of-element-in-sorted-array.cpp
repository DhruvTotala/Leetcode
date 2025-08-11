class Solution {
public:
    int findFirst(vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1, ans = -1;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (nums[mid] == target) {
                ans = mid;
                h = mid - 1; // keep searching left
            } else if (nums[mid] > target) {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

    int findLast(vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1, ans = -1;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (nums[mid] == target) {
                ans = mid;
                l = mid + 1; // keep searching right
            } else if (nums[mid] > target) {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirst(nums, target);
        int last = findLast(nums, target);
        return {first, last};
    }
};
