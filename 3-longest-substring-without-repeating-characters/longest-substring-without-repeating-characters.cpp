class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map <char, int> mp;
        int i = 0;
        int ans = 0;
        for(int j = 0; j < n; j++) {
            char ch = s[j];
            if(mp.find(ch) != mp.end() && mp[ch] >= i) {
                i = mp[ch] + 1;
            }
            mp[ch] = j;
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};