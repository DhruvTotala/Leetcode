class Solution {
public:
    int maximumCount(vector<int>& nums) {
         int n = nums.size();
        int pos_index = lower_bound(nums.begin(), nums.end(), 1) - nums.begin();
        int neg_index = upper_bound(nums.begin(), nums.end(), -1) - nums.begin();
        int pos_count = n - pos_index;
        int neg_count = neg_index;

        return max(pos_count, neg_count);
    }
    
};