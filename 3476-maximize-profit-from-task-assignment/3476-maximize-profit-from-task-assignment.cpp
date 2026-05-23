#define i23 long long

class Solution {
public:
    long long maxProfit(vector<int>& workers, vector<vector<int>>& tasks) {
        i23 res = 0;
        std::sort(begin(tasks), end(tasks), [&] (const auto &i, const auto &j) {
            return (i[0] != j[0] ? i[0] < j[0] : i[1] > j[1]);
        });

        std::unordered_map<int, int> umap;
        for (int w : workers) {
            umap[w]++;
        }

        i23 mx = 0;

        for (std::vector<int> t : tasks) {
            if (umap.count(t[0])) {
                res += t[1];
                umap[t[0]]--;
                if (umap[t[0]] == 0) {
                    umap.erase(t[0]);
                }
            } else {
                mx = std::max(mx, (i23)t[1]);
            }
        }

        res += mx;
        return res;
    }
};