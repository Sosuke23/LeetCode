class Solution {
public:
    string convertNumber(string s) {

        std::unordered_map<std::string, std::string> umap = {
            {"zero", "0"},  {"one", "1"},  {"two", "2"}, {"three", "3"},
            {"four", "4"},  {"five", "5"}, {"six", "6"}, {"seven", "7"},
            {"eight", "8"}, {"nine", "9"}};

        int n = (int)s.size();
        std::string t = "";
        std::string res = "";
        for (int i = 0; i < n; i++) {
            t = s.substr(i, std::min(n - i, 3));
            if (umap.find(t) != umap.end()) {
                res += umap[t];
                i += 2;
                continue;
            }

            t = s.substr(i, std::min(n - i, 4));
            if (umap.find(t) != umap.end()) {
                res += umap[t];
                i += 3;
                continue;
            }

            t = s.substr(i, std::min(n - i, 5));
            if (umap.find(t) != umap.end()) {
                res += umap[t];
                i += 4;
                continue;
            }
        }
        return res;
    }
};