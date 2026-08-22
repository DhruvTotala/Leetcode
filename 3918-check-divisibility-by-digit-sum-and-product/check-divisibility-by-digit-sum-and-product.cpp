class Solution {
public:
    bool checkDivisibility(int n) {
        int sum_d = 0;
        int prod_d = 1;
        int num = n;
        while(num > 0) {
            sum_d += num % 10;
            prod_d *= num % 10;
            num /= 10;
        }
        return n % (sum_d + prod_d) == 0;
    }
};