class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector <string> ans;
        int n = s.size();
        int curr = 0;
        while(curr < n) {
            ans.push_back(s.substr(curr, k));
            curr += k;
        }
        ans.back() += string(k - ans.back().length(), fill);
        return ans;
    }
};