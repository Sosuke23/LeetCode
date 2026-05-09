class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        std::vector<int> res(2, 0);
        for (std::string event : events) {
            if (event == "W") {
                res[1]++;
                if (res[1] == 10) {
                    return res;
                }
            } else if (event == "NB" or event == "WD") {
                res[0]++;
            } else {
                res[0] += (event[0] - '0');
            }
        }
        return res;
    }
};