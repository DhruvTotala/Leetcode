class Solution {
public:

    int countsub(int i, int curr_or, vector<int>& nums, int max_or) {
        if(i == nums.size()) {
            if(curr_or == max_or) {
                return 1;
            }
                return 0;
        }


        int take_count = countsub(i + 1, curr_or | nums[i], nums, max_or);

        int not_taken_count = countsub(i + 1, curr_or, nums, max_or);
        return take_count + not_taken_count;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int max_or = 0;
        for(int num : nums) {
            max_or |= num;
        }
        int curr_or = 0;
        return countsub(0, curr_or, nums, max_or);
    }
};