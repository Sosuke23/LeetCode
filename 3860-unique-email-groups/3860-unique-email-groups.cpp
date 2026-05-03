class Solution {
public:
    int uniqueEmailGroups(vector<string>& emails) {
        int res = 0;
        std::unordered_set<std::string> uset;

        for (std::string email : emails) {
            std::string domain = email.substr(email.find('@') + 1);

            for (auto &d : domain) {
                d = tolower(d);
            }

            std::string local = email.substr(0, email.find('@'));

            std::string norm_local = "";
            for (int i = 0; i < (int)local.size(); i++) {
                if (local[i] == '+') {
                    break;
                } else if (local[i] == '.') {
                    continue;
                }
                norm_local += tolower(local[i]);
            }
            norm_local += "@" + domain;
            uset.insert(norm_local);
        }

        return (int)uset.size();
    }
};