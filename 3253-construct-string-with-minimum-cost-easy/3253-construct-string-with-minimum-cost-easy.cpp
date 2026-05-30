class Solution {
public:
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        
        int n = (int)target.size();
        vector<long long> dp (n + 1, INT_MAX);

        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < words.size(); j++) {
                std::string word = words[j];
                int cost = costs[j];

                if (i + (int)word.size() <= n and target.substr(i, (int)word.size()) == word) {
                    dp[i + (int)word.size()] = min(dp[i + (int)word.size()], dp[i] + cost);
                }
            }
        }


        return dp[n] >= INT_MAX ? -1 : (int)dp[n];

    }
};