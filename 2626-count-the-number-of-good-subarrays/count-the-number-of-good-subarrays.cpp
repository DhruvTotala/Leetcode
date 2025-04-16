class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long res = 0;
        unordered_map<int, int> freq;
        int left = 0;
        long long count = 0;

        for (int right = 0; right < nums.size(); ++right) {
            count += freq[nums[right]];
            freq[nums[right]]++;

            while (count >= k) {
                res += nums.size() - right;
                freq[nums[left]]--;
                count -= freq[nums[left]];
                left++;
            }
        }

        return res;
    }
};