class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = i; j < n; j++) {
                if(nums[j] == target) count++;
                int len = j - i + 1;
                if(count > len / 2) ans++;
            }
        }
        return ans;
    }
};