class Solution {
public:
    int reverseBits(int n) {
        unsigned int ans = 0;
        for(int i = 0; i < 32; i++) {
            int l_bit = n & 1;
            ans = ans << 1;
            ans = ans | l_bit;
            n = n >> 1;
        }
        return ans;
    }
};