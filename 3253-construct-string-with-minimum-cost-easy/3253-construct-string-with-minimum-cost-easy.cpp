class Solution {
public:
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        
        int n = (int)target.size();
        vector<long long> dp (n + 1, INT_MAX);

        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < (int)words.size(); j++) {
                if (i + (int)words[j].size() <= n and target.substr(i, (int)words[j].size()) == words[j]) {
                    dp[i + (int)words[j].size()] = min(dp[i + (int)words[j].size()], dp[i] + costs[j]);
                }
            }
        }


        return dp[n] >= INT_MAX ? -1 : (int)dp[n];

    }
};