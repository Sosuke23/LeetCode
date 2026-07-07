class Solution {
public:
    long long sumAndMultiply(int n) {
        std::string st = "";
        int sum = 0;
        for (auto x : std::to_string(n)) {
            if (x != '0') {
                st += x;
                sum += (x - '0');
            }
        }

        if (st.empty()) {
            return 0;
        }

        long long res = 1LL * stoi(st) * sum;
        return res;
    }
};