class Solution {
public:
    int n;
    vector<string> result;

    bool isvalid(string str) {
        if(str[0] == '0') return false;
        int val = stoi(str);
        return val <= 255;
    }
    void solve(string &s, string curr, int parts, int idx) {
        if(idx == n && parts == 4) {
            curr.pop_back();
            result.push_back(curr);
            return;
        }
        if(idx + 1 <= n) {
        solve(s, curr + s.substr(idx, 1) + ".", parts + 1, idx + 1);
        }

        if(idx + 2 <= n && isvalid(s.substr(idx, 2))) {
        solve(s, curr + s.substr(idx, 2) + ".", parts + 1, idx + 2);
        }

        if(idx + 3 <= n && isvalid(s.substr(idx, 3))) {
        solve(s, curr + s.substr(idx, 3) + ".", parts + 1, idx + 3);
        }

    }

    vector<string> restoreIpAddresses(string s) {
        n = s.size();
        result.clear();

        if(n > 12) return {};
        int parts = 0;
        string curr = "";
        solve(s, curr, parts, 0);
        return result;
    }
};