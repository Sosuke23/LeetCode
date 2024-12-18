class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> res;
        for (int i = 0; i < (int)prices.size(); i++) {
            int j = i + 1;
            int dis = 0;
            while (j < (int)prices.size()) {
                if (prices[j] <= prices[i]) {
                    dis = prices[j];
                    break;
                }
                j++;
            }
            res.push_back(prices[i] - dis);
        }
        return res;
    }
};