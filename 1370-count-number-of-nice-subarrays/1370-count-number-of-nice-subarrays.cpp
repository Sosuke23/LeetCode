class Solution {
public:
    int numberOfSubarrays(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> pref;
        int curr = 0, res = 0;
        pref[0] = 1;

        for (auto x : nums) {
            curr += (x % 2);
            if (pref.find(curr - k) != pref.end()) {
                res += pref[curr - k];
            }
            pref[curr]++;
        }
        return res;
    }
};