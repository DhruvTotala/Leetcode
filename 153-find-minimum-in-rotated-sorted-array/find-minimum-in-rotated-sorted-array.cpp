class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int ans = 0;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(nums[mid] <= nums[n - 1]) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return nums[ans];
    }
};