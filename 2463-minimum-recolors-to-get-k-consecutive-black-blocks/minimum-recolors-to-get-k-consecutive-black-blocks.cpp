class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int ans = INT_MAX;
        for(int i = 0; i <= n - k; i++) {
            int min_op = 0;
            for(int j = i; j - i + 1 <= k; j++) {
                if(blocks[j] == 'W') min_op ++;
            }
            ans = min(ans, min_op);
        }
        return ans;
    }
};