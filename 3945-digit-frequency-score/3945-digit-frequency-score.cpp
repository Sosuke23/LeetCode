class Solution {
public:
    int digitFrequencyScore(int n) {
        std::unordered_map<char, int> mp;
        for (char x : std::to_string(n)) {
            mp[x]++;
        }

        int res = 0;
        for (auto [dig, freq] : mp) {
            res += (dig - '0') * freq;
        }
        return res;
    }
};