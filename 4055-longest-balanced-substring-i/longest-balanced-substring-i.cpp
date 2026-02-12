class Solution {
public:

    bool isvalid(vector <int>& freq) {
        int common = 0;
        for(int i = 0; i < 26; i++) {
            if(freq[i] == 0) continue;
            if(common == 0) common = freq[i];
            else if(freq[i] != common) return false;
        }
        return true;
    }
    int longestBalanced(string s) {
        int n = s.size();
        int max_len = 0;
        for(int i = 0; i < n; i++) {
            vector <int> freq(26, 0);
            for(int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                if(isvalid(freq)) {
                    max_len = max(max_len, j - i + 1);
                }
            }
        }
        return max_len;
    }
};