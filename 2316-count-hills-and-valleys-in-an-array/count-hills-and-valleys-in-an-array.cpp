class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        int i = 0;
        int j = 1;
        while(j + 1 < n) {
            if((nums[i] < nums[j] && nums[j] > nums[j + 1]) || (nums[i] > nums[j] && nums[j] < nums[j + 1])) {
                count++;
                i = j;
            }
            j++;
        }
        return count;
    }
};