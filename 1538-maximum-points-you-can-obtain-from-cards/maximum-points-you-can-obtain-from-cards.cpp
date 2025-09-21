class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total = accumulate(cardPoints.begin(), cardPoints.end(), 0);

        // If we take all cards
        if (k == n) return total;

        int window = n - k; // size of subarray to exclude
        int curr_sum = 0;

        // First window
        for (int i = 0; i < window; i++) {
            curr_sum += cardPoints[i];
        }

        int min_sum = curr_sum;

        // Sliding window
        for (int i = window; i < n; i++) {
            curr_sum += cardPoints[i] - cardPoints[i - window];
            min_sum = min(min_sum, curr_sum);
        }

        return total - min_sum;
    }
};
