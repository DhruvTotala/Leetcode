class Solution {
public:
    int minimumPushes(string word) {
        // Frequency vector to store count of each letter
        vector<int> frequency(26, 0);

        // Count occurrences of each letter
        for (char& c : word) {
            ++frequency[c - 'a'];
        }

        // Sort frequencies in descending order
        sort(frequency.rbegin(), frequency.rend());

        int totalPushes = 0;

        // Calculate total number of presses
        for (int i = 0; i < 26; ++i) {
            if (frequency[i] == 0) break;
            totalPushes += (i / 8 + 1) * frequency[i];
        }

        return totalPushes;
    }
};