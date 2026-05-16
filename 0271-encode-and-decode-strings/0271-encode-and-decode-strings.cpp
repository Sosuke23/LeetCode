class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        std::string res = "";
        for (std::string s : strs) {
            res += s + "so" + '$';
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        std::vector<std::string> res;
        std::string t = "";
        int prev = 0;
        int n = (int)s.size();
        for (int i = 0; i < n - 2; i++) {
            std::string p = "";
            p += s[i];
            p += s[i + 1];
            p += s[i + 2];
            if (p == "so$") {
                res.push_back(t);
                t = "";
                prev = i + 3;
                i += 2;
            } else {
                t += s[i];
            }
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));