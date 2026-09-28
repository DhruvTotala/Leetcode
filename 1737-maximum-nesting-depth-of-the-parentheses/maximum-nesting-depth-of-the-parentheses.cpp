class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;

        stack <int> st;
        for(char ch : s) {
            if(ch == '(') st.push(ch);
            else if(ch == ')') st.pop();
            ans = max(ans, (int)st.size());
        }
        return ans;
    }
};