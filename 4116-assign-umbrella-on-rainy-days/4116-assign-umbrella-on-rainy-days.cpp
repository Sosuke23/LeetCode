class Solution {
public:
    vector<string> assignUmbrella(vector<int>& rain) {
        int n = (int)rain.size();

        std::vector<std::string> res(n);
        std::array<int, 2> cnt{0};
        for (int i = 0; i < n; i++) {
            if (rain[i] == 0) {
                res[i] = "None";
            } else {
                if (rain[i] == 1 and i + 1 < n and rain[i + 1] == 1) {
                    if (cnt[0] > cnt[1]) {
                        res[i] = "Bob";
                        cnt[1]++;
                    } else {
                        res[i] = "Alice";
                        cnt[0]++;
                    }
                } else {
                    res[i] = "Bob";
                    cnt[1]++;
                }
            }
        }
        return res;
    }
};