class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector <int> ans;
        int count = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] != 0) ans.push_back(nums[i]);
            if(nums[i] == 0) count++;
        }
        while(count--) {
            ans.push_back(0);
        }
        for(int i = 0; i < n; i++) {
            nums[i] = ans[i];
        }
    }
};