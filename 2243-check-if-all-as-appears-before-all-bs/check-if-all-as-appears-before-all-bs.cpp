class Solution {
public:
    bool checkString(string s) {
        int n = s.size();
        int lasta = -1;  // Index of the last occurrence of 'a'
        int firstb = n;  // Index of the first occurrence of 'b'
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'a') {
                lasta = max(lasta, i);
            } else {
                firstb = min(firstb, i);
            }
        }
        return lasta < firstb;
    }
};