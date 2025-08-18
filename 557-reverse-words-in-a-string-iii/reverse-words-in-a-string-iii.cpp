class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        stringstream ss(s);
        string word = "";
        string result = "";
        while(ss >> word) {
            reverse(word.begin(), word.end());
            result += word + " ";
        }
        return result.substr(0, result.size() - 1);
    }
};