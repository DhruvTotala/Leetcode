class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int totalPoints = 0;

        if (x > y) {
            // Remove "ab" first (higher points), then "ba"
            totalPoints += removeSubstring(s, "ab", x);
            totalPoints += removeSubstring(s, "ba", y);
        } else {
            // Remove "ba" first (higher or equal points), then "ab"
            totalPoints += removeSubstring(s, "ba", y);
            totalPoints += removeSubstring(s, "ab", x);
        }

        return totalPoints;
    }

    int removeSubstring(string& inputString, string targetSubstring,
                        int pointsPerRemoval) {
        int totalPoints = 0;
        int writeIndex = 0;

        // Iterate through the string
        for (int readIndex = 0; readIndex < inputString.size(); readIndex++) {
            // Add the current character
            inputString[writeIndex++] = inputString[readIndex];

            // Check if we've written at least two characters and
            // they match the target substring
            if (writeIndex > 1 &&
                inputString[writeIndex - 2] == targetSubstring[0] &&
                inputString[writeIndex - 1] == targetSubstring[1]) {
                writeIndex -= 2;  // Move write index back to remove the match
                totalPoints += pointsPerRemoval;
            }
        }

        // Trim the string to remove any leftover characters
        inputString.erase(inputString.begin() + writeIndex, inputString.end());

        return totalPoints;
    }
};