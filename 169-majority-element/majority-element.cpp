class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cand = -1;
        int votes = 0;
        for(int i = 0; i < n; i++) {
            if(votes == 0) {
               cand = nums[i];
               votes++;
            } else if(nums[i] == cand) {
                votes++;
            } else {
                votes--;
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == cand) cnt++;
        }
        if(cnt > (n / 2)) return cand;
        return -1;
    }
};