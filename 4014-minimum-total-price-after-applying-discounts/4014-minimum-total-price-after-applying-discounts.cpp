class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        std::sort(rbegin(prices), rend(prices));
        std::sort(begin(discounts), end(discounts));

        double res = 0;
        for (int p : prices) {
            if (!discounts.empty()) {
                res += (double)p * (100 - discounts.back()) / 100;
                discounts.pop_back();
            } else {
                res += p;
            }
        }

        return res;
    }
};