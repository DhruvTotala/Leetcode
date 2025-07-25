class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int max_neg = INT_MIN;
        unordered_set <int> st;
        for(int i = 0; i < n; i++) {
            if(nums[i] <= 0) max_neg = max(max_neg, nums[i]);
            else if(!st.count(nums[i])) {
                sum += nums[i];
                st.insert(nums[i]);
            }
        }
        return sum == 0 ? max_neg : sum;
    }
};