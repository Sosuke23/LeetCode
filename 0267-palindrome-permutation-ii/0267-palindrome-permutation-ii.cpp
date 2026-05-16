class Solution {
public:
    vector<string> generatePalindromes(string s) {
        int n = (int)s.size();
        std::vector<std::string> res;
        std::unordered_map<char, int> umap;

        std::string now(n, 'a');
        for (char c : s) {
            umap[c]++;
        }

        std::function<void(int, int)> f = [&] (int i, int j) {
            if (i > j) {
                res.push_back(now);
                return;
            }

            for (auto &[c, _] : umap) {
                int req = 1 + (i != j);
                if (umap[c] >= req) {
                    now[i] = now[j] = c;
                    umap[c] -= req;
                    f(i + 1, j - 1);
                    umap[c] += req;
                }
            }
        };

        f(0, n - 1);

        return res;
    }
};