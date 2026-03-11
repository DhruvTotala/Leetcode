class Solution {
public:
    int bitwiseComplement(int n) {
        int m = n | 1;
        for(int i = 0; i <= 4; i++) {
            m |= m >> (1 << i);
        }
        return n ^ m;
    }
};