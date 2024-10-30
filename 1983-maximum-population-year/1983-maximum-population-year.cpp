class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int, int> mp;
        for (vector<int> l : logs) {
            mp[l[0]]++;
            mp[l[1]]--;
        }

        int res = 0;
        int mx = 0;
        int cnt = 0;
        for (auto [year, c] : mp) {
            cnt += c;
            if (cnt > mx) {
                mx = cnt;
                res = year;
            }
        }
        return res;
    }
};