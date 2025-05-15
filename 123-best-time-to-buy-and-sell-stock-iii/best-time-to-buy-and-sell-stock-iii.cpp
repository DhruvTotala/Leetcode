class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int first_buy = INT_MIN, first_sell = 0;
        int second_buy = INT_MIN, second_sell = 0;

        for (int price : prices) {
            first_buy = max(first_buy, -price);               // max profit after first buy
            first_sell = max(first_sell, first_buy + price);  // max profit after first sell
            second_buy = max(second_buy, first_sell - price); // max profit after second buy
            second_sell = max(second_sell, second_buy + price); // max profit after second sell
        }

        return second_sell;
    }
};
