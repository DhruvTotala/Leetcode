class Solution {
public:
    bool isPalindrome(string s) {
        string close;
        for(char ch: s) {
            if(isalnum(ch)) close += tolower(ch);
        }
        int i = 0;
        int j = close.size() - 1;
        while(i < close.size() && j >= 0) {
            if(close[i++] != close[j--]) return false;
        }
        return true;
    }
};