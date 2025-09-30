class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        while(n > 1) {
            vector <int> ans;
            for(int i = 0; i < n - 1; i++) {
                ans.push_back((nums[i] + nums[i + 1]) % 10);
            }
            nums = ans;
            n--;
        }
        return nums[0];
    }
};