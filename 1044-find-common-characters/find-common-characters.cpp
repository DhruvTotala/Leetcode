class Solution {
public:

    void fillc(string& words, int mp[26]) {
         for(char& ch : words) mp[ch - 'a']++;
    }
    vector<string> commonChars(vector<string>& words) {
        vector <string> ans;
        int n = words.size();
        int mp[26] = {0};

        fillc(words[0], mp);
        for(int i = 1; i < n; i++) {
            int temp[26] = {0};
            fillc(words[i], temp);

            for(int j = 0; j < 26; j++) mp[j] = min(mp[j], temp[j]);
        }
        for(int i = 0; i < 26; i++) {
            int c = mp[i];
            while(c--) {
                ans.push_back(string(1, i + 'a'));
            }
        }
        return ans; 
    }
};