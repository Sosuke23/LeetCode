class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& cost) {
        int sz = (int)days.size();
        vector<int> just{1, 7, 30};
        vector<int> dp(sz + 4, 0);
        for (int i = 1; i <= sz; i++) {
            dp[i] = dp[i - 1] + cost[0];
            for (int j = 0; j < 3; j++) {
                int x = upper_bound(days.begin(), days.end(), days[i - 1] - just[j]) - days.begin();
                dp[i] = min(dp[i], dp[x] + cost[j]);
            }
        }
        return dp[sz];
    }
};