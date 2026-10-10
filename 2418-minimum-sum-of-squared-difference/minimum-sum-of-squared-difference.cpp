class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        const int MOD = 100000;
        vector <long long> f_d(MOD + 1, 0);
        int max_diff = 0;
        long long total_d = 0;

        for(int i = 0; i < nums1.size(); i++) {
            int diff = abs(nums1[i] - nums2[i]);
            f_d[diff]++;
            total_d += diff;
            max_diff = max(max_diff, diff);
        }

        long long k = (long long) k1 + k2;

        if(total_d <= k) return 0;

        for(int i = max_diff; i > 0 && k > 0; i--) {
            long long moves = min(k, f_d[i]);
            f_d[i] -= moves;
            f_d[i - 1] += moves;
            k -= moves;
        }

        long long ans = 0;
        for(int i = 1; i <= max_diff; i++) {
            ans += (long long) i * i * f_d[i];
        }
        return ans;
    }
};