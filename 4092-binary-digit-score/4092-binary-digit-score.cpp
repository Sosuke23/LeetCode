class Solution {
public:
    int calculateScore(int a, int b) {
        int set_a {__builtin_popcount(a)};
        int set_b {__builtin_popcount(b)};

        if (set_a >= set_b) {
            return set_a * set_b;
        }

        return set_b / set_a;
    }
};