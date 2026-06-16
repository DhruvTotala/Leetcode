class Solution {
public:
    string processStr(string s) {
        string ans = "";
        for(auto it : s) {
            if(it == '*') {
                if(ans.size()) {
                    ans.pop_back();
                }
            } else if(it == '#') {
                ans += ans;
            } else if(it == '%') {
                ans = string(ans.rbegin(), ans.rend());
            } else {
                ans += it;
        }
    }
    return ans;
    }
};