class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curr = prices[0];
        int res = 0;
        for (int i = 1; i < (int)prices.size(); i++) {
            res = std::max(res, prices[i] - curr);
            curr = std::min(curr, prices[i]);
        }
        return res;
    }
};