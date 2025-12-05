class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        vector <int> psum(n + 1, 0);
        psum[0] = nums[0];
        for(int i = 1; i < n - 1; i++) {
            psum[i] = psum[i - 1] + nums[i];
        }
        int count = 0;
        for(int i = 0; i < n - 1; i++) {
            int l_sum = psum[i];
            int sum = 0;
            for(int j = i + 1; j < n; j++) {
                sum += nums[j];
            }
            if(((l_sum - sum) % 2) == 0) count++;
        }
        return count;
    }
};