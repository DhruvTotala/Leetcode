class Solution {
public:

    bool isvowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    int maxFreqSum(string s) {
        unordered_map <char, int> mp;
        for(char ch : s) mp[ch]++;
        int max_v = 0;
        int max_c = 0;
        for(auto it : mp) {
            char ch = it.first;
            int frq = it.second;
            if(isvowel(ch)) {
                max_v = max(max_v, frq);
            } else {
                max_c = max(max_c, frq);
            }
        }
        return max_v + max_c;
    }
};