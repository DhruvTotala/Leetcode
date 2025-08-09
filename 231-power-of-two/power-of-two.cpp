class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        long long val = 1;
        while(val < n) {
            val *= 2;
        }
        return val == n;
    }
};