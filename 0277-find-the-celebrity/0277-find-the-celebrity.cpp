/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        
        // i knows j -> outflow
        // celebrity = inflow = n - 1 and outflow = 0

        std::vector<int> in(n, 0), out(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }
                if (knows(i, j)) {
                    out[i]++;
                    in[j]++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (in[i] == n - 1 and out[i] == 0) {
                return i;
            }
        }
        return -1;
    }
};