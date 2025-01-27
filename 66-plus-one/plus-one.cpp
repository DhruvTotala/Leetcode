class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int idx = digits.size() - 1; // Start from the last digit
        while (idx >= 0) {
            if (digits[idx] == 9) {
                digits[idx] = 0; // Set current digit to 0 if it's 9
            } else {
                digits[idx] += 1; // Otherwise, just add 1
                return digits; // Return the result immediately
            }
            idx--; // Move to the next digit
        }
        digits.insert(digits.begin(), 1); // If all digits were 9, add a leading 1
        return digits;
    }
};