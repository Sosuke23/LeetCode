class Solution {
public:
    int countDigitOne(int n) {
        vector<int> nums;
        for (auto x : to_string(n)) {
            nums.push_back(x - '0');
        }
        int Dp[10][10][2];
        memset(Dp, -1, sizeof(Dp));
        auto Solve = [&] (auto Solve, int pos, int cnt, int f) {
            if (pos == (int)nums.size()) {
                return cnt;
            }
            if (Dp[pos][cnt][f] != -1) {
                return Dp[pos][cnt][f];
            }
            int to = (f == 0 ? nums[pos] : 9);
            int res = 0;
            for (int i = 0; i <= to; i++) {
                int ncnt = cnt;
                int nf = f;
                if (f == 0 and i < to) {
                    nf = 1;
                }
                if (i == 1) {
                    ncnt++;
                }
                res += Solve(Solve, pos + 1, ncnt, nf);
            }
            return Dp[pos][cnt][f] = res;
        };

        int res = Solve(Solve, 0, 0, 0);
        return res;
    }
};