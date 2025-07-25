class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set <int> st;
        for(int it : nums) {
            if(it > 0) st.emplace(it);
        }
        if(st.empty()) return *max_element(nums.begin(), nums.end());
        return accumulate(st.begin(), st.end(), 0);
    }
};