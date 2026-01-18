class Solution {
public:
    
    vector <string> res;
    void helper(string &s, int n, int open, int close) {
        if(s.length() == 2 * n) {
                res.push_back(s);
            return;
        }

        if(open < n) {
        s.push_back('(');
        helper(s, n, open + 1, close);
        s.pop_back();
        }

        if(close < open) {
        s.push_back(')');
        helper(s, n, open, close + 1);
        s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        int close = 0;
        int open = 0;
        helper(s, n, open, close);
        return res;
    }
};