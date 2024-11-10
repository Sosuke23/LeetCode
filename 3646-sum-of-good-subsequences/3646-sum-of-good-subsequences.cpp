class Solution {
public:
    int mod = 1000000007;
    int sumOfGoodSubsequences(vector<int>& nums) {
        map<int, int> cnt, sum;
        for (int i : nums) {
            cnt[i] += (cnt[i - 1] + cnt[i + 1] + 1) % mod;
            cnt[i] %= mod;
            sum[i] += (sum[i - 1] + sum[i + 1]) % mod;
            sum[i] %= mod;
            sum[i] += (long long)(cnt[i - 1] + cnt[i + 1] + 1) % mod * i % mod;
            sum[i] %= mod;
        }
        int res = 0;
        for (auto& p : sum) {
            res += p.second;
            res %= mod;
        }
        return res;
    }
};