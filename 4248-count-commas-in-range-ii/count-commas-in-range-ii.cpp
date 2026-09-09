class Solution {
public:
typedef long long ll;
    long long countCommas(long long n) {
        ll ans = 0;
        ll start = 1000;
        while(start <= n) {
            ans += (n - start + 1);
            start *= 1000;
        }
        return ans;
    }
};