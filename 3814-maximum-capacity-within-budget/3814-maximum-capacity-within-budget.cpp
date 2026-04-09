class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        std::vector<std::pair<int, int>> arr;
        int res = 0;
        for (int i = 0; i < (int)costs.size(); i++) {
            if (costs[i] < budget) {
                arr.push_back({costs[i], capacity[i]});
                res = std::max(res, capacity[i]);
            }
        }

        if (arr.empty()) {
            return 0;
        }

        std::sort(begin(arr), end(arr));
        int n = (int)arr.size();
        std::vector<int> max_cap(n), c(n);

        for (int i = 0; i < n; i++) {
            max_cap[i] = arr[i].second;
            c[i] = arr[i].first;
            if (i > 0) {
                max_cap[i] = std::max(max_cap[i], max_cap[i - 1]);
            }
        }
        
        for (int i = 0; i < (int)arr.size(); i++) {
            int cost = arr[i].first;
            int caps = arr[i].second;

            int rem_limit = budget - cost - 1;
            if (rem_limit < arr[0].first || i == 0) {
                continue;
            }

            int k = (int)(upper_bound(begin(c), end(c), rem_limit) - begin(c)) - 1;
            k = std::min(k, i - 1);
            if (k >= 0) {
                res = std::max(res, caps + max_cap[k]);
            }
            
        }
        return res;
    }
};


