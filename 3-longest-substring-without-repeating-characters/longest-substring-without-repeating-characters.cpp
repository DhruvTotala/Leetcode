class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0;
        int r = 0;
        vector <int> hashh(256, -1);
        int max_len = 0;
        while(r < n) {
            if(hashh[s[r]] != -1) {
                if(hashh[s[r]] >= l) l = hashh[s[r]] + 1;
            }
            hashh[s[r]] = r;
            int len = r - l + 1;
            max_len = max(max_len, len);
            r++;
        }
        return max_len;
    }
};