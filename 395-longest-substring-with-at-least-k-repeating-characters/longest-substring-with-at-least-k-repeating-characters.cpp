class Solution {
public:
    int longestSubstring(string s, int k) {
        int ans = 0;
        int n = s.size();
        for(int i = 1; i <= 26; i++) {
            vector <int> freq(26, 0);
            int l = 0, r = 0;
            int unique = 0;
            int countatleastk = 0;
            while(r < n) {
                if(unique <= i) {
                    int idx = s[r] - 'a';
                    if(freq[idx] == 0) unique++;
                    freq[idx]++;
                    if(freq[idx] == k) countatleastk++;
                    r++;
                } else {
                    int idx = s[l] - 'a';
                    if(freq[idx] == k) countatleastk--;
                    freq[idx]--;
                    if(freq[idx] == 0) unique--;
                    l++;
                }
                if(unique == i && unique == countatleastk) ans = max(ans, r - l);
            }
        }
        return ans;
    }
};