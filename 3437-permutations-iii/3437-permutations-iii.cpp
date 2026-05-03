class Solution {
public:
    vector<vector<int>> permute(int n) {
        std::vector<std::vector<int>> res;
        std::vector<int> p(n);
        std::iota(begin(p), end(p), 1);

        do {
            bool ok = false;
            for (int i = 0; i < n - 1; i++) {
                if ((p[i] % 2 == p[i + 1] % 2)) {
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                res.push_back(p);
            }
        } while (std::next_permutation(begin(p), end(p)));

        return res;
    }
};