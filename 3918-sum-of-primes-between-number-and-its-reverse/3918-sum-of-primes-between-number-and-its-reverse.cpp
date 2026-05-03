class Solution {
public:

    bool prime(int x) {
        if (x <= 1) {
            return false;
        }
        for (int i = 2; i <= sqrt(x); i++) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }

    int sumOfPrimesInRange(int n) {
        int res = 0;
        std::string a = std::to_string(n);
        reverse(begin(a), end(a));
        int rev_n = std::stoi(a);

        if (rev_n < n) {
            std::swap(n, rev_n);
        }

        for (int i = n; i <= rev_n; i++) {
            if (prime(i)) {
                res += i;
            }
        }
        return res;
    }
};