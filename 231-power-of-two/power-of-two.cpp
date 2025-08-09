class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false; // powers of two are positive

        for (int i = 0; (1LL << i) <= n; i++) { // use shifting instead of pow()
            if ((1LL << i) == n) return true;  // exact match
        }
        return false;
    }
};
