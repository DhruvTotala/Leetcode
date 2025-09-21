class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        return ((goal + goal).find(s) != string::npos);
    }
};