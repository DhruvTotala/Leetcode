class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    int n = strs.size();
    if(strs.empty()) return ""; 
    sort(strs.begin(), strs.end());
    string f = strs[0];
    string l = strs[n - 1]; 
    int i = 0;
    while(i < f.size() && f[i] == l[i]) i++;
    return f.substr(0,i);
    }
};