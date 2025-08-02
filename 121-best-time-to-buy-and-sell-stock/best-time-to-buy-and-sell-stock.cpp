class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        int min_value = prices[0];
        for(int i = 1; i < n; i++) {
            // selling today 
            int profit = prices[i] - min_value;
            ans = max(ans, profit);
            min_value = min(min_value, prices[i]);
        }
        return ans;
    }
};