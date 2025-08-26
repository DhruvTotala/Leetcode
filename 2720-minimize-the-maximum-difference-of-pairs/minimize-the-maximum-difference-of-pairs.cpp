class Solution {
public:

    bool ispossible(vector <int>& nums, int mid, int p) {
        int count = 0;
        int i = 0;
        while(i < nums.size() - 1) {
            if(abs(nums[i] - nums[i + 1]) <= mid) {
                count++;
                i += 2;
            } else {
                i++;
            }
            if(count >= p) return true;
        }
        return false;
    }

    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int low = 0;
        int high = nums[n - 1] - nums[0];
        int ans = 0;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(ispossible(nums, mid, p)) {
               ans = mid;
               high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};