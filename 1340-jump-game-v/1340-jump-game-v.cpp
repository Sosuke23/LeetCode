class Solution {
public:
    int dfs(int i, int d, vector<int>& arr, vector<int>& dp) {
        if (i < 0 && i >= arr.size()) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        int ans = 0;

        for (int j = 1; j <= d; j++) {
            if (i + j < arr.size()) {
                if (arr[i] > arr[i + j]) {
                    ans = max(ans, 1 + dfs(i + j, d, arr, dp));
                } else {
                    break;
                }
            } else {
                break;
            }
        }
        for (int j = 1; j <= d; j++) {
            if (i - j >= 0) {
                if (arr[i] > arr[i - j]) {
                    ans = max(ans, 1 + dfs(i - j, d, arr, dp));
                } else {
                    break;
                } 
            } else {
                break;
            }
        }
        return dp[i] = ans;
    }
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size(), ans = 0;
        vector<int> dp(n, -1);

        for (int i = 0; i < n; i++) {
            ans = max(ans, dfs(i, d, arr, dp));
        }
        return ans + 1;
    }
};