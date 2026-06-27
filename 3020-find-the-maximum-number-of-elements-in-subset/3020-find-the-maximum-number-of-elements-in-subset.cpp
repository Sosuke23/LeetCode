class Solution {
public:
    #define i64 long long
    i64 Sqrt(i64 n) {
        i64 a = sqrt(n);
        while ((a + 1) * (a + 1) <= n) {
            a++;
        }
        while(a * a > n){
            a--;
        }
        return a;
    }
    int maximumLength(vector<int>& nums) {
        int n = (int)nums.size();
        unordered_map<int, int> f;
        for (auto x : nums) {
            f[x]++;
        }
        int res = 1;
        for (auto &[key, val] : f) {
            if (key == 1) {
                res = max(res, val - (1 - (val % 2)));
                continue;
            }
            int now = 1;
            int sq = Sqrt(key);
            int orig = key;
            while (sq * sq == orig and f.count(sq) and f[sq] >= 2) {
                now += 2;
                orig = sq;
                sq = Sqrt(orig);
            }
            res = max(res, now);
        }
        return res;
    }
};