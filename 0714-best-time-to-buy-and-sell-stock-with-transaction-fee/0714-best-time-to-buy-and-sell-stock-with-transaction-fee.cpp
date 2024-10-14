class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = (int)prices.size();
        if (n < 2) {
            return 0;
        }
        int buy = -prices[0];
        int sell = 0;
        for(int i = 1; i < n; i++) {
            int new_buy = max(buy, sell - prices[i]);    
            int new_sell = max(sell, buy + prices[i] - fee);
         
            buy = new_buy;
            sell = new_sell;
        }
        return sell;
    }
};