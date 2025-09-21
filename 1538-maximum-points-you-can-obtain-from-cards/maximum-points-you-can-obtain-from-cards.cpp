class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int max_sum = 0;
        int l_sum = 0;
        int r_sum = 0;
        for(int i = 0; i < k; i++) l_sum += cardPoints[i];
        max_sum = l_sum;
        int r_index = n - 1;
        for(int i = k - 1; i >= 0; i--) {
            l_sum = l_sum - cardPoints[i];
            r_sum = r_sum + cardPoints[r_index];
            r_index--;
            max_sum = max(max_sum, l_sum + r_sum);
        }
        return max_sum;
    }
};