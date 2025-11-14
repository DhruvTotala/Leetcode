class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(m > n) return "";
        if(s == t) return s;
        vector <int> hashh(256, 0);
        for(int i = 0; i < m; i++) hashh[t[i]]++;
        int min_len = INT_MAX;
        int start = -1;
        int count = 0;
        int l = 0;
        int r = 0;
        while(r < n) {
            if(hashh[s[r]] > 0) {
                count++;
            }
            hashh[s[r]]--;
            while(count == m) {
                if(r - l + 1 < min_len) {
                    min_len = r - l + 1;
                    start = l;
                }
                hashh[s[l]]++;
                if(hashh[s[l]] > 0) count--;
                l++;
            }
            r++;
        }
        return start == -1 ? "" : s.substr(start, min_len);
    }
};