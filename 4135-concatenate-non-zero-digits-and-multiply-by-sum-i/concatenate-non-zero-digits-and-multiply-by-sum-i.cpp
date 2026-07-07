class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        long long x = 0;
        long long sum = 0;
        for(char ch : s) {
            int d = ch - '0';
            sum += d;
            if(d > 0) x = x * 10 + d;
        }
        return x * sum;
    }
};