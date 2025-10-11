class Solution {
public:
    bool scoreBalance(string s) {
        int n = s.size();
        int total = 0;

        for(char ch : s) total += (ch - 'a' + 1);
        int l_sum = 0;
        for(int i = 0; i < n - 1; i++) {
            l_sum += (s[i] - 'a' + 1);
            int r_sum = total - l_sum;
            if(r_sum == l_sum) return true;
        }
        return false;
    }
};