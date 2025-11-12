class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int t = p.size();
        if(n < t) return {};
        vector <int> ans;
        vector <int> freq_p(26, 0);
        vector <int> freq_s(26, 0);
        for(char ch : p) freq_p[ch - 'a']++;
        for(int i = 0; i < t; i++) {
            freq_s[s[i] - 'a']++;
        }
        if(freq_s == freq_p) ans.push_back(0);
        for(int i = t; i < n; i++) {
            freq_s[s[i] - 'a']++;
            freq_s[s[i - t] - 'a']--;
            if(freq_s == freq_p) ans.push_back(i - t + 1);
        }
        return ans;
    }
};