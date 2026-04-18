class Solution {
public:
    int mirrorDistance(int n) {
        string rev_n = to_string(n);
        reverse(rev_n.begin(), rev_n.end());
        return abs(n - stoi(rev_n));
    }
};