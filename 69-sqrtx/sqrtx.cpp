class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        int ans = 1;
        for(int i = 1; i <= x; i++) {
            if(1LL * i * i <= x) {
                ans = i;
            } else {
                break;
            }
        }
        return ans;
    }
};