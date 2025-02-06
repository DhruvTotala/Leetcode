class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
    vector <int> minfreq(26, INT_MAX);
    for(string word : words){
        vector<int> freq(26, 0);
        for(auto ch : word) freq[ch - 'a']++;
    for(int i = 0; i < 26; i++) minfreq[i] = min(minfreq[i], freq[i]);
    }
    vector <string> ans;
    for(int i = 0; i < 26; i++){
        while(minfreq[i] > 0){
            ans.push_back(string(1, i + 'a'));
            minfreq[i]--;
        }
    }
    return ans;
    }
};