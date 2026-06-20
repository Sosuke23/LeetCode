class Solution {
public:
    vector<int> minOperations(vector<int>& nums) {
        std::vector<int> palindrome;
        int n = (int)nums.size();

        auto palin = [&] (int x) {
            bitset<13> b(x);
            std::string s = b.to_string();
            reverse(begin(s), end(s));
            while (!s.empty() and s.back() == '0') {
                s.pop_back();
            }
            
            int ns = (int)s.size();
            for (int i = 0; i < ns / 2; i++) {
                if (s[i] != s[ns - i - 1]) {
                    return false;
                }
            }
            return true;
        };

        for (int i = 1; i <= 6000; i++) {
            if (palin(i)) {
                palindrome.push_back(i);
            }
        }

        std::vector<int> res;
        for (int x : nums) {
            auto it = std::lower_bound(begin(palindrome), end(palindrome), x);
            res.push_back(*it - x);
            if (it != begin(palindrome)) {
                it--;
                res.back() = std::min(res.back(), x - *it);
            } 
        }

        return res;

    }
};