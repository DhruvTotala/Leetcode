class Solution {
public:
    int binaryGap(int n) {
        string s = bitset<32>(n).to_string();
        
        int prev = -1;
        int maxGap = 0;
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '1') {
                if(prev != -1) {
                    maxGap = max(maxGap, i - prev);
                }
                prev = i;
            }
        }
        
        return maxGap;
    }
};