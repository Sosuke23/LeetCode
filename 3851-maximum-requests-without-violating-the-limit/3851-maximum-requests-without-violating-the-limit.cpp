class Solution {
public:
    int maxRequests(vector<vector<int>>& requests, int k, int window) {
        std::unordered_map<int, std::deque<int>> umap;

        std::sort(begin(requests), end(requests), [&] (const auto &a, const auto &b) {
            return b[1] > a[1];
        });

        int res = 0;
        for (std::vector<int> req : requests) {
            umap[req[0]].push_back(req[1]);
        }

        auto f = [&] (std::deque<int> &t) {
            
            int j = 0;
            int ret = (int)t.size();
            std::deque<int> dq;
            for (int x : t) {
                dq.push_back(x);
                if ((int)dq.size() > k) {
                    if (dq.back() - dq.front() <= window) {
                        ret--;
                        dq.pop_back();
                    } else {
                        dq.pop_front();
                    }
                }
            }
            
            return ret;

        };

        for (auto &[user, time] : umap) {
            res += f(time);
        }

        return res;

    }
};