class Solution {
public:
    int nextBeautifulNumber(int n) {
        std::array<int, 13> arr = {1, 22, 122, 333, 1333, 4444, 14444, 22333, 55555,
                                    122333, 155555, 224444, 666666};

        int res = 1224444;
        std::string st = std::to_string(n);
        for (auto x : arr) {
            std::string a = std::to_string(x);
            if ((int)a.size() > (int)st.size()) {
                res = std::min(res, stoi(a));
            } else if ((int)a.size() == (int)st.size()) {
                do {
                    if (a > st) {
                        res = std::min(res, stoi(a));
                    }
                } while (next_permutation(begin(a), end(a)));
            }
        }
        return res;
    }
};