class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector <int> suff(100);
        suff[n - 1] = nums.back();

        for(int i = n - 2; i >= 0; i--) {
            suff[i] = min(suff[i + 1], nums[i]);
        }

        int max_ans = 0;
        for(int i = 0; i < n; i++) {
            max_ans = max(max_ans, nums[i]);
            if(max_ans - suff[i] <= k) return i;
        }
        return -1;
    }
};