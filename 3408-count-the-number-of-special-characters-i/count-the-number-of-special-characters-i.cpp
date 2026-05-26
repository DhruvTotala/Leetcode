class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set <char> st(word.begin(), word.end());
        int c = 0;
        for(char ch = 'a'; ch <='z'; ch++) {
            if(st.count(ch) && st.count(ch - 'a' + 'A')) c++;
        }
        return c;
    }
};