class Solution {
public:
    string betterCompression(string str) {

        std::array<int, 26> cnt = {0};
        for (int i = 0; i < (int)str.size();) {
            if (str[i] >= 'a' and str[i] <= 'z') {
                std::string freq = "";
                int j = i + 1;
                for (; j < (int)str.size(); j++) {
                    if (str[j] >= '0' and str[j] <= '9') {
                        freq += str[j];
                    } else {
                        break;
                    }
                }
                cnt[str[i] - 'a'] += std::stoi(freq);
                i = j;
            }
        }

        std::string res = "";
        for (int i = 0; i < 26; i++) {
            if (cnt[i] == 0) {
                continue;
            }
            res += ('a' + i);
            res += std::to_string(cnt[i]);
        }

        return res;
    }
};