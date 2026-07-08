class Solution {
public:
    const int MOD = 1e9 + 7;
    typedef long long ll;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector <int> non_zerocount(n, 0);
        vector <ll> num_upto(n, 0);
        vector <ll> digit_sum(n, 0);
        vector <ll> pow10(n + 1, 0);

        pow10[0] = 1;
        for(int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        non_zerocount[0] = (s[0] != '0') ? 1 : 0;
        for(int i = 1; i < n; i++) {
            int digit = s[i] - '0';
            non_zerocount[i] = non_zerocount[i - 1] + ((digit != 0) ? 1 : 0);
        }
        num_upto[0] = s[0] - '0';
        for(int i = 1; i < n; i++) {
            int digit = s[i] - '0';
            if(digit != 0) {
                num_upto[i] = ((num_upto[i - 1] * 10) + digit) % MOD; 
            } else {
                num_upto[i] = num_upto[i - 1];
            }
        }
        digit_sum[0] = s[0] - '0';
        for(int i = 1; i < n; i++) {
            int digit = s[i] - '0';
            digit_sum[i] = digit_sum[i - 1] + digit;
        }
        int q = queries.size();
        vector <int> ans(q);
        for(int i = 0; i < q; i++) {
            int l = queries[i][0];
            int r = queries[i][1];

            ll sum = digit_sum[r] - ((l == 0) ? 0 : digit_sum[l - 1]);
            ll num_before = (l == 0) ? 0 : num_upto[l - 1];
            int k = non_zerocount[r] - ((l == 0) ? 0 : non_zerocount[l - 1]);
            ll x = (num_upto[r] - (num_before * pow10[k] % MOD) + MOD) % MOD;
            ans[i] = (x * (sum % MOD)) % MOD;
        }
        return ans;
    }
};