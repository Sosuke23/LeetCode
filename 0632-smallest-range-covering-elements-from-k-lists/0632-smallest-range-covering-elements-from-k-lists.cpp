class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>> vp;
        map<int, int> mpp;

        for (int i = 0; i < nums.size(); i++) {
            for (auto vbn : nums[i]) {
                vp.push_back({vbn, i});
            }
        }

        sort(vp.begin(), vp.end());
        int st = -1, en = -1, len = 100000000;
        int lo = 0, hi = -1;

        for (; lo < vp.size(); lo++) {
            while (mpp.size() < nums.size()) {
                hi++;
                if (hi >= vp.size()) {
                    return {st, en};
                }
                mpp[vp[hi].second]++;
            }

            if (len > vp[hi].first - vp[lo].first + 1) {
                len = vp[hi].first - vp[lo].first + 1;
                st = vp[lo].first, en = vp[hi].first;
            }

            if (mpp[vp[lo].second] == 1) {
                mpp.erase(vp[lo].second);
            }
            else {
                mpp[vp[lo].second]--;
            }
        }

        return {st, en};
    }
};