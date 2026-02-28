class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1e9 + 7;
        long long ans = 0;
        int bits = 0;

        for(int i = 1; i <= n; i++) {
            if((i & (i - 1)) == 0)
                bits++;
            ans = ((ans << bits) + i) % MOD;
        }

        return ans;
    }
};