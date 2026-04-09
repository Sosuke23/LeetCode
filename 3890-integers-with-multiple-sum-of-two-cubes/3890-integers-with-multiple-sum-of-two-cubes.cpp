class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        std::vector<int> res;

        std::unordered_map<int, int> mp;
        for (int i = 1; i <= 1000; i++) {
            for (int j = i + 1; j <= 1000; j++) {
                long long a = i * i * i + j * j * j;
                if (a > n) {
                    break;
                }
                mp[a]++;
                if (mp[a] == 2) {
                    res.push_back(a);
                }
            }
        }
        std::sort(begin(res), end(res));
        return res;
    }
};