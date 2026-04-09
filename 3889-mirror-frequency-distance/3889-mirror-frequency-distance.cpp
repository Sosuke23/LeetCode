class Solution {
public:
    int mirrorFrequency(string s) {
        int res = 0;
        std::unordered_map<int, int> mp;
        std::unordered_map<int, int> dig;
        for (char c : s) {
            if (c >= '0' and c <= '9') {
                dig[c - '0']++;
            } else {
                mp[c - 'a']++;
            }
            
        }

        std::array<int, 26> visited = {0};
        std::array<int, 10> used = {0};

        for (char x : s) {
            int c = 0, m = 0;
            if (x >= 'a' and x <= 'z') {
                c = x - 'a';
                m = 25 - (x - 'a');
                if (visited[c] or visited[m]) {
                    continue;
                }
                visited[c] = 1;
                visited[m] = 1;
                res += std::abs(mp[c] - mp[m]);
            } else {
                c = x - '0';
                m = 9 - (x - '0');
                if (used[c] or used[m]) {
                    continue;
                }
                used[c] = 1;
                used[m] = 1;
                res += std::abs(dig[c] - dig[m]);
            }
            
        }

        return res;
    }
};