class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map <int, int> mpp;
        mpp[0] = 1;
        int n = nums.size();
        int sum = 0;
        int count = 0;
        for(int x : nums) {
            sum += x;
            if(mpp.find(sum - goal) != mpp.end()) {
                count += mpp[sum - goal];
            }
            mpp[sum]++;
        }
        return count;
    }
};