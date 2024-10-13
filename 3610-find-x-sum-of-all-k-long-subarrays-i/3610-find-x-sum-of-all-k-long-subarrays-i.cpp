class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        map<int, int> mp;
        int n = (int)nums.size();
        vector<int> res;
        auto f = [&] () {
            vector<pair<int, int>> a;
            for (auto &[x, y] : mp) {
                a.push_back({y, x});
            }
            sort(begin(a), end(a));
            int j = x;
            int ret = 0;
            while (j-- and !a.empty()) {
                ret += a.back().first * a.back().second;
                a.pop_back();
            }
            return ret;
        };
        int b = 0;
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
            if (i >= k - 1) {
                int p = f();
                res.push_back(p);
                mp[nums[b]]--;
                if (mp[nums[b]] == 0) {
                    mp.erase(nums[b]);
                }
                b++;
            }
        }
        return res;
    }
};