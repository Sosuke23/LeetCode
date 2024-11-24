class Solution {
public:
    int maxRemoval(vector<int>& a, vector<vector<int>>& queries) {
        int n = a.size();
        vector<vector<int>> b(n);
        for (auto& v : queries) {
            int x = v[0], y = v[1] + 1;
            b[x].push_back(y);
        }
        for (int i = 0; i < n; ++i) {
            sort(b[i].rbegin(), b[i].rend());
        }

        vector<int> d(n + 1);
        multiset<int, greater<>> can;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (i > 0) {
                d[i] += d[i - 1];
            }
            int cur = a[i] + d[i];
            for (auto& k : b[i]) {
                can.insert(k);   
            }

            if (cur <= 0) {
                continue;
            }
            while (!can.empty() && *can.rbegin() <= i) {
                can.erase(std::prev(can.end()));
            }
            if (can.size() < cur) {
                return -1;
            }
            while (cur--) {
                int k = *can.begin();
                can.erase(can.begin());
                d[i] -= 1;
                d[k] += 1;
                cnt += 1;
            }
        }
        return queries.size() - cnt;
    }
};