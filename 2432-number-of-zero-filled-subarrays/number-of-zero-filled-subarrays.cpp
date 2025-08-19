class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0;
        long long curr = 0;
        for(int x : nums) {
            if(x == 0) {
                curr++;
                count += curr;
            } else {
                curr = 0;
            }
        }
        return count;
    }
};