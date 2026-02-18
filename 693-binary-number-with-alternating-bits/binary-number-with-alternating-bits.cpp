class Solution {
public:
    bool hasAlternatingBits(int n) {
        string ans = "";
        while(n > 0) {
            ans = char((n % 2) + '0') + ans;
            n /= 2;
        }
        for(int i = 0; i < ans.size() - 1; i++) {
            if(ans[i] == ans[i + 1]) return false;
        }
        return true;
    }
};