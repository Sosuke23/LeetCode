class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> Cnt(n, 0);
        map<int, int> mp;
        for (auto& v : edges) {
            Cnt[v[1]] += 1;
        }

        int res = 0;
        int c = 0;
        for (int i = 0; i < n; i++) {
            if (Cnt[i] == 0) {
                c += 1;
                res = i;
            }
        }
        return (c > 1 ? -1 : res);
    }
};