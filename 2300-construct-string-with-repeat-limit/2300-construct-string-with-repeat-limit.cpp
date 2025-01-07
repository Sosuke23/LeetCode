class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        array<int, 26> cnt {0};
        for (auto x : s) {
            cnt[x - 'a'] += 1;
        }
        std::string res = "";
        int n = (int)s.size();
        while ((int)res.size() < n) {
            for (int i = 25; i >= 0; i--) {
                if (cnt[i] > 0) {
                    int can = std::min(repeatLimit, cnt[i]);
                    res += std::string(can, 'a' + i);
                    cnt[i] -= can;
                    bool ok = false;
                    if (cnt[i]) {
                        for (int j = i - 1; j >= 0; j--) {
                            if (cnt[j] > 0) {
                                res += 'a' + j;
                                cnt[j] -= 1;
                                ok = true;
                                break;
                            }
                        }
                        if (!ok) {
                            return res;
                        }
                    }
                    
                    break;
                }
            }
        }
        return res;
    }
};