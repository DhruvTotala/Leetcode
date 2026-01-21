class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        for(int& it : nums) {
            int ans = -1;
            int d = 1;
            while((it & d) != 0) {
                ans = it - d;
                d <<= 1;
            }
            it = ans;
        }
        return nums;
    }
};