class Solution {
public:
    string generateTag(string caption) {
        std::string res = "";
        for (int i = 0; i < (int)caption.size(); i++)  {
            if (caption[i] == ' ' and i + 1 < (int)caption.size() and caption[i + 1] != ' ') {
                res += toupper(caption[i + 1]);
                i++;
            } else if (caption[i] != ' ') {
                res += tolower(caption[i]);
            }
        }

        res = "#" + res;
        res[1] = tolower(res[1]);
        return res.substr(0, 100);
    }
};