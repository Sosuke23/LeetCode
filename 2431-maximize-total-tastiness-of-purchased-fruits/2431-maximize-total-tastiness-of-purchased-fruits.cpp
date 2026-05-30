class Solution {
public:
    int dp[101][1001][6];
    int f(int i, int n, std::vector<int>  &price, std::vector<int> &tastiness, int max_amount, int max_coupons) {

        if (i == n) {
            return 0;
        }

        if (dp[i][max_amount][max_coupons] != -1) {
            return dp[i][max_amount][max_coupons];
        }

        int take = 0;
        if (max_amount >= price[i]) {
            take = tastiness[i] + f(i + 1, n, price, tastiness, max_amount - price[i], max_coupons);
        }
        int not_take = f(i + 1, n, price, tastiness, max_amount, max_coupons);
        int take_with_coupons = 0;
        if (max_amount >= price[i] / 2 and max_coupons > 0) {
            take_with_coupons = tastiness[i] + f(i + 1, n, price, tastiness, max_amount - (price[i] / 2), max_coupons - 1);
        }
        
        return dp[i][max_amount][max_coupons] = max({take, not_take, take_with_coupons});
    }
    int maxTastiness(vector<int>& price, vector<int>& tastiness, int maxAmount, int maxCoupons) {
        memset(dp, -1, sizeof(dp));
        int res = f(0, (int)price.size(), price, tastiness, maxAmount, maxCoupons);
        return res;
    }
};