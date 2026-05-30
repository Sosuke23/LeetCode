class Solution {
public:
    vector<int> countSteppingNumbers(int low, int high) {
        vector<int> res;
        if (low == 0) {
            res.push_back(0);
        }
        for (int i = 1; i < 10; i++) {
            f(low, high, i, res);
        }
        sort(res.begin(), res.end());
        return res;
    }
    void f(int low, int high, long int cur, vector<int>& res) {
        if (cur > high) {
            return;
        }
        if (cur >= low) {
            res.push_back(cur);
        }

        int last = cur % 10;
        long int next = cur * 10 + last + 1;
        long int prev = cur * 10 + last - 1;

        if (last != 0) {
            f(low, high, prev, res);
        }
        if (last != 9) {
            f(low, high, next, res);
        }
    }
};