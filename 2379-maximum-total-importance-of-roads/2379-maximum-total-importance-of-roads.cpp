class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        std::vector<int> cnt(n, 0);
        for (auto x : roads) {
            cnt[x[0]]++;
            cnt[x[1]]++;
        }
        long long res = 0;
        std::sort(begin(cnt), end(cnt));
        for (int i = 0; i < n; i++) {
            res += 1LL * cnt[i] * (i + 1);
        }
        return res;
    }
};