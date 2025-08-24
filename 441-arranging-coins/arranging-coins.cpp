class Solution {
public:
    int arrangeCoins(int n) {
        int ans;
        long long count = 0;
        for(int i = 1; i <= n; i++) {
            count += i;
            if(count > n) {
                ans = i - 1;
                break;
            }
        }
        return ans;
    }
};