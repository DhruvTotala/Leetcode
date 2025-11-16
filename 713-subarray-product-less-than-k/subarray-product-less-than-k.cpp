class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        for(int i = 0; i < n; i++) {
            long long prod_c = 1;
            for(int j = i; j < n; j++) {
                 prod_c = prod_c * nums[j];
                if(prod_c < k) count++;
                else break;
            }
        }
        return count;
    }
};