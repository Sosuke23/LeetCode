class Solution {
public:
    vector<int> goodIndices(string s) {
        std::vector<int> res;
        int n = (int)s.size();
        for (int i = 0; i < n; i++) {

            if (i == 0 and s[i] == '0') {
                res.push_back(i);
                continue;
            }
            int how_much = 0;
            int a = i;
            while (a) {
                a /= 10;
                how_much++;
            }
            
            std::string p = s.substr(i - how_much + 1, how_much);
            if (p == std::to_string(i)) {
                res.push_back(i);
            }

        }

        return res;
    }
};