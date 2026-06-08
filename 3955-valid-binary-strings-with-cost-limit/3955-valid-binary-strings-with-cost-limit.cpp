class Solution {
public:
    std::vector<std::string> res;

    void f(int index, int n, int k, int cost,  bool is_one, std::string &curr) {
        if (cost > k) {
            return;
        }

        if (index == n) {
            res.push_back(curr);
            return;
        }

        curr += '0';
        f(index + 1, n, k, cost, false, curr);
        curr.pop_back();

        if (!is_one) {
            curr += '1';
            f(index + 1, n, k, cost + index, true, curr);
            curr.pop_back();
        }
    }
    
    vector<string> generateValidStrings(int n, int k) {
        std::string curr = "";
        f(0, n, k, 0, false, curr);
        return res;
    }
};