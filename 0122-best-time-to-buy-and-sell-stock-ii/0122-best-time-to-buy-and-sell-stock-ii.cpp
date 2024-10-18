class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = (int)prices.size();
        int prev = prices[0];
        int res = 0;
        for (int i = 1; i < n; i++) {
            if (prices[i] > prev) {
                res += prices[i] - prev;
            }
            prev = prices[i];
        }
        return res;
    }
};