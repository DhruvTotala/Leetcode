class Solution {
public:
    double myPow(double x, int n) {
      if(n == 0) return 1;

      double ans = 1.0;
      long long p = abs((long long) n);
      while(p > 0){
        if(p % 2 == 1) ans *= x;
        x *= x;
        p/= 2;
      }
      return (n < 0) ? (1.0 / ans) : ans;
    }
};