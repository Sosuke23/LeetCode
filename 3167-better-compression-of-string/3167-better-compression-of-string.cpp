class Solution {
public:
    string betterCompression(string str) {
        std::map<char, int> mp;
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
                mp[str[i]] += std::stoi(freq);
                i = j;
            }
        }

        std::string res = "";
        for (auto &[key, val] : mp) {
            res += key;
            res += std::to_string(val);
        }
        return res;
    }
};