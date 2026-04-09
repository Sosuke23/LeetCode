class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        std::unordered_map<std::string, int> umap;
        for (std::string w : words) {
            if ((int)w.size() < k) {
                continue;
            }
            umap[w.substr(0, k)]++;
        }

        int res = 0;
        for (auto [word, count] : umap) {
            if (count > 1) {
                res++;
            }
        }
        return res;
    }
};