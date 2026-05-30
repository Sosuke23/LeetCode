class Solution {
public:
    bool confusingNumber(int n) {
        if (n == 0) {
            return false;
        }
        string st = to_string(n);
        string A = st;
        set<int> no = {2, 3, 4, 5, 7};
        set<int> yes = {0, 1, 6, 8, 9};
        for (auto &x : st) {
            if (no.count(x - '0')) {
                return false;
            } else if (x == '6') {
                x = '9';
            } else if (x == '9') {
                x = '6';
            }
        }

        while (st.back() == '0') {
            st.pop_back();
        }

        reverse(begin(st), end(st));
        return (st != A);
    }
};