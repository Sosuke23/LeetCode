class Solution {
public:
    int passwordStrength(string password) {
        int res {0};
        std::unordered_set<char> uset;
        for (char p : password) {
            if (!uset.count(p)) {
                if (p >= 'a' and p <= 'z') {
                    res++;
                } else if (p >= 'A' and p <= 'Z') {
                    res += 2;
                } else if (p >= '0' and p <= '9') {
                    res += 3;
                } else if (p == '!' or p == '@' or p == '#' or p == '$') {
                    res += 5;
                }
            }
            uset.insert(p);
        }
        return res;
    }
};