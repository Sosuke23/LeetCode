class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        std::array<char, 5> dig = {'0', '1', '6', '8', '9'};
        std::array<char, 5> rev_dig = {'0', '1', '9', '8', '6'};

        std::queue<std::string> q;
        int curr_len = 0;

        if (n % 2 == 0) {
            q.push("");
        } else {
            curr_len = 1;
            q.push("0");
            q.push("1");
            q.push("8");
        }

        while (curr_len < n) {
            curr_len += 2;
            for (int j = (int)q.size(); j > 0; j--) {
                std::string num = q.front();
                q.pop();

                for (int i = 0; i < 5; i++) {
                    if (curr_len != n or dig[i] != '0') {
                        q.push(dig[i] + num + rev_dig[i]);
                    }
                }
            }
        }

        std::vector<std::string> res;
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }

        return res;
    }
};

/*
1 6 8 9 0
*/