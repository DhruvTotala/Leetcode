class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        int temp = sum;
        if(sum > 9 * num || sum < 0) return "";
        string ans = "";
        for(int i = 0; i < num; i++) {
            int d = min(9, sum);
            ans += ('0' + d);
            sum -= d;
        }
        if(sum > 0) return "";
        return ans;
    }
};