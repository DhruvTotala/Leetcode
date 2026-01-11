class Solution {
public:
    double ans(double x, long y) {
        if(y == 0) return 1;
        double h = ans(x, y / 2);

        if(y % 2 == 0) return h * h;
        else return h * h * x;
    }
    double myPow(double x, int n) {
        long y = n;
        if(y < 0) {
            x = 1 / x;
            y = -y;
        }
        return ans(x, y);
    }
};