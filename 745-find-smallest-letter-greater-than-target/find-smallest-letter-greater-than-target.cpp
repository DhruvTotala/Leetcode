class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto ub = upper_bound(letters.begin(), letters.end(), target);
        if (ub == letters.end()) return letters[0];
        return *ub; 
    }
};