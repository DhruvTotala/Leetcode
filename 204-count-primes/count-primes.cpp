class Solution {
public:
    int countPrimes(int n) {
        vector <bool> isprime(n, true);
        if(n <= 2) return 0;
        isprime[0] = false;
        isprime[1] = false;
        for(int i = 2; i * i < n; i++) {
            if(isprime[i]) {
                for(int j = i * i; j < n; j += i) {
                    isprime[j] = false;
                }
            }
        }

        int ans = 0;
        for(int i = 2; i < n; i++) {
            if(isprime[i]) ans++;
        }
        return ans;
    }
};