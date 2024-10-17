class Solution {
public:
    int maximumSwap(int num) {
        std::string p = std::to_string(num);
        std::string res = p;
        for (int i = 0; i < (int)p.size(); i++) {
            std::string t = p;
            for (int j = i + 1; j < (int)p.size(); j++) {
                if (t[j] > t[i]) {
                    std::swap(t[i], t[j]);
                    res = std::max(res, t);
                    std::swap(t[i], t[j]);
                }
            }
        }
        return atoi(res.c_str());
    }
};