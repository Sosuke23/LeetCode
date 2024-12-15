class Solution {
public:
    double Profit(int pass, int total) {
        return (double) (pass + 1) / (total + 1) - (double) pass / total;
    }
    double maxAverageRatio(vector<vector<int>>& classes, int K) {
        priority_queue<pair<double, array<int, 2>>> PQ;
        double tot = 0;
        for (auto &x : classes) {
            tot += (double) x[0] / x[1];
            cout << Profit(x[0], x[1]) << '\n';
            PQ.push({Profit(x[0], x[1]), {x[0], x[1]}});
        }

        while (K--) {
            auto [to_add, D] = PQ.top();
            PQ.pop();
            tot += to_add;
            PQ.push({Profit(D[0] + 1, D[1] + 1), {D[0] + 1, D[1] + 1}});
        }
        double res = (double) tot / (int)classes.size();
        return res;
    }
};