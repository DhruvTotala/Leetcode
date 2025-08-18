class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        int idx = 0;
        unordered_map <char, int> mp;
        for(char ch : s) mp[ch]++;
        for(int i = 0; i < n; i++) if(mp[s[i]] == 1) return i;
        return -1;
    }
};