class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ans = 0;
        int low = 0;
        int n = nums.size();
        int high = n - 1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(target == nums[mid]){
                ans = mid;
                break;
            }else {
                if(nums[mid] > target) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            ans = low;
        }
        return ans;
    }
};