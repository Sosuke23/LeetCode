class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<double, pair<int, int>>> p;
        int n = (int)arr.size();
        for (int i = 0; i + 1 < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double div = (double) arr[i] / arr[j];
                p.push_back({div, {i, j}});
            }
        }
        k -= 1;
        sort(begin(p), end(p));
        return {arr[p[k].second.first], arr[p[k].second.second]};
    }
};