class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map <char, int> mp;
        for(char ch : s) mp[ch]++;
        if(s.size() != t.size()) return false;
        for(int i = 0; i < t.size(); i++) {
            if(mp.find(t[i]) == mp.end() || mp[t[i]] == 0) return false;
            else mp[t[i]]--;
        }
        return true;
    }
};