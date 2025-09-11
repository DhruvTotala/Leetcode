class Solution {
public:

    bool isvowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }

    string sortVowels(string s) {
        string temp;
        for(char ch : s) {
            if(isvowel(ch)) temp += ch;
        }

        sort(temp.begin(), temp.end());
        int j = 0;
        string ans;
        for(int i = 0; i < s.size(); i++) {
            if(isvowel(s[i])) {
                ans += temp[j];
                j++;
            } else {
                ans += s[i];
            }
        }
        return ans;
    }
};