class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int res = 0;
        int left = 0;
        int sum = 0;
        int freq[10001] = {0};
        for(int right = 0; right < nums.size(); right++) {
            while(freq[nums[right]] > 0) {
                int prev = nums[left];
                sum -= prev;
                freq[prev]--;
                left++;
            }
            sum += nums[right];
            freq[nums[right]]++;
            res = max(res, sum);
        }
        return res;
    }
};