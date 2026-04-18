class Solution {
public:
    int mirrorDistance(int n) {
        string rev_n = to_string(n);
        reverse(rev_n.begin(), rev_n.end());
        int ans = stoi(rev_n);
        return abs(n - ans);
    }
};