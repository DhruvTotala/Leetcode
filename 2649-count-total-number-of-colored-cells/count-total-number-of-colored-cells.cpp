class Solution {
public:
    long long coloredCells(int n) {
        long long ans = 1;
        n = n - 1;
        if(n == 0) return ans;
        for(int i = 1; i <= n; i++){
            ans = ans + (4 * i); 
        }
        return ans;
    }
};