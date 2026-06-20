class Solution {
public:
    bool isDigitorialPermutation(int n) {
        std::string st = to_string(n);
        std::sort(begin(st), end(st));

        std::vector<long long> perm(10);
        perm[0] = 1;
        perm[1] = 1;
        for (int i = 2; i <= 9; i++) {
            perm[i] = 1LL * perm[i - 1] * i;
        }

        do {
            long long a = 0;
            for (char x : st) {
                a += perm[x - '0'];
            }

            long long b = std::stoi(st);
            if (a == b and st[0] != '0') {
                return true;
            }

        } while (std::next_permutation(begin(st), end(st)));

        return false;

    }
};