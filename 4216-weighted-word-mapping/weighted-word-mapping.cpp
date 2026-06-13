class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        ans.reserve(words.size());
        for(string word : words) {
            int s = 0;
            for(char ch : word) {
                s += weights[ch - 'a'];
            }
            ans += 'z' - s % 26;
        }
        return ans;
    }
};