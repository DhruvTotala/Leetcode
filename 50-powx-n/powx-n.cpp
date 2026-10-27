class Solution {
public:
    double solve(double x, long long n) {
        if (n < 0)
            return 1.0 / solve(x, -n);
        if (n == 0) return 1.0;

        if (n % 2 == 0)
            return solve(x * x, n / 2);

        return x * solve(x * x, (n - 1) / 2);
    }

    double myPow(double x, int n) {
        long long power = n;
        return solve(x, power);
    }
};