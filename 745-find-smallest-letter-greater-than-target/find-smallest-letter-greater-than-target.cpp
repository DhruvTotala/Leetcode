class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int ub = upper_bound(letters.begin(), letters.end(), target) - letters.begin();
        if (ub == n) return letters[0];
        return letters[ub];
    }
};