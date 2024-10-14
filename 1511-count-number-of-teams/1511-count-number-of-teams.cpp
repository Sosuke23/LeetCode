class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = (int)rating.size();
        std::vector<std::pair<int, int>> a;
        for (int i = 0; i < n; i++) {
            a.push_back({rating[i], i});
        }

        int res = 0;
        sort(begin(a), end(a));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if ((a[i].second < a[j].second) and (a[j].second < a[k].second)) {
                        res += 1;
                    } else if ((a[i].second > a[j].second) and (a[j].second > a[k].second)) {
                        res += 1;
                    }
                }
            }
        }
        return res;
    }
};