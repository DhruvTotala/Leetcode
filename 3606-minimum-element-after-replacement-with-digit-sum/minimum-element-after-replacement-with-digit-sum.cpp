class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = 37;
        for(int it : nums) {
            int d = 0;
            while(it > 0) {
                d += it % 10;
                it /= 10;
            }
            ans = min(ans, d);
        }
        return ans;
    }
};