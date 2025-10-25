class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;
        int monday = 1;
        while(n > 0) {
            for(int i = 0; i < min(n, 7); i++) {
                ans += monday + i;
            }
            n -= 7;
            monday++;
        }
        return ans; 
    }
};