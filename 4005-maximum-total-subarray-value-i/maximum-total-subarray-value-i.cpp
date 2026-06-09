class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int m1 = INT_MAX;
        int m2 = INT_MIN;
        for(int it : nums) {
            m1 = min(m1, it);
            m2 = max(m2, it);
        }
        return (long long) (m2 - m1) * k;
    }
};