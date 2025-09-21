class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        string s1 = "";
        stack <char> st;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                if(!st.empty()) s1 += '(';
                st.push(s[i]);
            }
            else if(s[i] == ')') {
                st.pop();
                if(!st.empty()) s1 += ')';
            }
        }
        return s1;
    }
};