class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int Alice = 0, Bob = 0;
        int lo = 0, hi = (int)piles.size() - 1;
        int now = 0;
        while (lo < hi) {
            if (now % 2 == 0) {
                if (piles[lo] >= piles[hi]) {
                    Alice += piles[lo];
                    lo += 1;
                }
                else {
                    Alice += piles[hi];
                    hi -= 1;
                }
            }
            else {
                if (piles[lo] <= piles[hi]) {
                    Bob += piles[lo];
                    lo += 1;
                }
                else {
                    Bob += piles[hi];
                    hi -= 1;
                }
            }
            now += 1;
        }

        return (Alice > Bob);
    }
};