class Solution {
public:
    long long maxScore(std::vector<int>& arr) {
        typedef long long i64;
        i64 res = 0;
        int n = (int)arr.size();

        auto f = [&] (std::vector<int> p) -> i64 {
            int _gcd = 0;
            i64 _lcm = 1;
            for (int i = 0; i < (int)p.size(); i++) {
                _gcd = std::gcd(_gcd, p[i]);
                _lcm = std::lcm(_lcm, p[i]);
            }
            i64 ret = 1LL * _gcd * _lcm;
            return ret;
        };
        
        res = f(arr);
        for (int i = 0; i < n; i++) {
            std::vector<int> a;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    a.push_back(arr[j]);
                }
            }
            res = std::max(res, f(a));
        }
        return res;
    }
};