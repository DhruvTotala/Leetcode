class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            rotate(s.begin(), s.begin() + 1, s.end());
            if(s == goal) return true;
        }
        return false;
    }
};