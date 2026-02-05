class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        for(int i = 0; i < n; i++) {
            int shift = nums[i] % n;
            int new_idx = (i + shift) % n;
            if(new_idx < 0) new_idx += n;
            result[i] = nums[new_idx];

        }
        return result;
    }
};