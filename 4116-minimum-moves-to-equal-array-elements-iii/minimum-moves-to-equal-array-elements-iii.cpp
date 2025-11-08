class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int max_ele = *max_element(nums.begin(), nums.end());
        for(int i = 0; i < n; i++) {
            count += abs(nums[i] - max_ele);
        }
        return count;
    }
};