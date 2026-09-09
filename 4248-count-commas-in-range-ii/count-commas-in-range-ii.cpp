class Solution {
public:
typedef long long ll;
    long long countCommas(long long n) {
        ll ans = 0;
        ll lower = 1000;
        int comma = 1;
        while(lower <= n) {
            ll upper = lower * 1000 - 1;
            if(upper > n) upper = n;

            ll count_nos = upper - lower + 1;
            ans += comma * count_nos;
            lower *= 1000;
            comma++;
        }
        return ans;
    }
};