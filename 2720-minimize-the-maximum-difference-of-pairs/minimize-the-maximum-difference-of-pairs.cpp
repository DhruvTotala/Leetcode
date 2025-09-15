class Solution {
public:

    bool isvalid(vector <int>& arr, int mid, int p) {
        int n = arr.size();
        int count = 0;
        for(int i = 0; i < n - 1; i++) {
            if(abs(arr[i] - arr[i + 1]) <= mid) {
                count++;
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
            if(isvalid(nums, mid, p)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
    return ans;    
    }
};