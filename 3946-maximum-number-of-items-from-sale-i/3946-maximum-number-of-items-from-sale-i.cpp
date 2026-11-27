class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        vector<int> dp(budget + 1, 0);

        int n = (int)items.size();
        vector<int> bonus(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    bonus[i]++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int b = budget; b >= items[i][1]; b--) {
                dp[b] = max(dp[b], dp[b - items[i][1]] + bonus[i] + 1);
            }

            for (int b = items[i][1]; b <= budget; b++) {
                dp[b] = max(dp[b], dp[b - items[i][1]] + 1);
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};